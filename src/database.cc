#include "database.h"

#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>
#include <queue>
#include <map>

#include "member.h"
#include "csv_reader.h"

namespace algdb {

Database::Database() {
}


Database::~Database() {
  for (auto event : events) {
    delete event; 
  }

  for (auto member : members) {
    delete member;
  }

  for (auto group : groups) {
    delete group;
  }
}

void Database::LoadEventData(const std::string &event_file, int limit) {
  CsvReader reader;
  reader.OpenFile(event_file.c_str());

  int count = 0;
  while(reader.NextEntry()) {
    count ++;
    if (count > limit) break;
    Event *event = new Event();
    for (int j = 0; j < 48; j++) {
      std::string cell = reader.NextCell();
      switch (j) {
      case 0:
        event->event_id = cell;
        break;
      case 3:
        event->duration = std::stoull(cell);
        break;
      case 6:
        event->fee = std::stoi(cell);
        break;
      case 14:
        event->group_id = std::stoull(cell);
        break;
      case 28:
        event->time = cell;
      case 47:
        event->yes_rsvp_count = std::stoi(cell);
        break;
      }
    }
    events.push_back(event);
  }
  std::cout << events.size() << " events loaded.\n";
}

void Database::LoadMemberData(const std::string &member_file, int limit) {
  CsvReader reader;
  reader.OpenFile(member_file.c_str());

  int count = 0;
  uint64_t last_id = 0;
  Member *member;

  while(reader.NextEntry()) {
    uint64_t id = std::stoull(reader.NextCell());
    if (id != last_id) {
      last_id = id;
      count++;
      if (count > limit) {
        break;
      }

      member = new Member();
      members.push_back(member);
      member->member_id = id;
      for (int j = 0; j < 13; j++) {
        std::string cell = reader.NextCell();
        switch (j) {
        case 5:
          member->lat = std::stod(cell);
          break;
        case 7:
          member->lon = std::stod(cell);
          break;
        case 8:
          member->member_name = cell;
          break;
        case 12:
          member->group_ids.push_back(std::stoull(cell));
        }
      }
      member_id_hash_index[member->member_id] = member;
    }
  }
  std::cout << members.size() << " merbers loaded.\n";
}

void Database::LoadGroupData(const std::string &group_file, int limit) {
  CsvReader reader;
  reader.OpenFile(group_file.c_str());

  int count = 0;
  while(reader.NextEntry()) {
    count++;
    if (count > limit) {
      break;
    }

    Group *group = new Group();
    for (int j = 0; j < 36; j++) {
      std::string cell = reader.NextCell();
      switch (j) {
      case 0:
        group->group_id = std::stoull(cell);
        break;
      case 20:
        group->group_name = cell;
        break;
      case 21:
        group->organizer_id = std::stoull(cell);
      case 29:
        group->rating = std::stof(cell);
        break;
      }
    }
    groups.push_back(group);
    group_id_hash_index[group->group_id] = group;
  }
  std::cout << groups.size() << " groups loaded.\n";
}

void Database::AssociateMembersWithGroups() {
  for (auto member : members) {
    for (auto group_id : member->group_ids) {

      // Check if the group_id is in the group_group_id_hash_index
      if (group_id_hash_index.find(group_id) != 
          group_id_hash_index.end()) {
        auto group = group_id_hash_index[group_id];
        member->groups.push_back(group);
        group->members.push_back(member);
      }
    }
  }
}

void Database::RandomizeGraph(int num_connections) {
  // Create some random connections to make the problem more interesting.
  srand(0);
  for (int i = 0; i < num_connections; i++) {
    int src_index = rand() % members.size();
    int dst_index = rand() % members.size();
    int group_index = rand() % groups.size();

    Member *src = members[src_index];
    Member *dst = members[dst_index];

    if (src == dst) continue;

    if (src->connecting_members.find(dst->member_id) == 
        src->connecting_members.end()) {
      MemberConnection conn;
      conn.group = groups[group_index];
      conn.dst = dst;
      src->connecting_members[dst->member_id] = conn;
      dst->connecting_members[src->member_id] = conn;
    }
  }
}


void Database::LoadData(const std::string &data_folder_path, 
                        int event_limit, 
                        int member_limit, 
                        int group_limit) {

  LoadEventData(data_folder_path + "/events.csv", event_limit);
  LoadMemberData(data_folder_path + "/members.csv", member_limit);
  LoadGroupData(data_folder_path + "/groups.csv", group_limit);
  AssociateMembersWithGroups();
  // RandomizeMembers();
}


void Database::BuildMemberGraph() {
  // Fill in your code here
 unsigned int i; 
 unsigned int j;
 unsigned int k;
 unsigned int l;
  for(i = 0; i < (members.size()-1); i++){
    for(j = i+1; j < members.size(); j++){
       for(k = 0; k < members[i]->groups.size(); k++){
         for(l = 0; l < members[j]->groups.size(); l++){
           if(members[i]->groups[k]->group_id == members[j]->groups[l]->group_id){
             //std::cout << "Connection: " << "(" << members[i]->member_id << ", " << members[j]->member_id << ", " << members[i]->groups[k]->group_id <<")" << "\n";
             MemberConnection connect;
             auto fill = members[i]->groups[k];
             connect.dst = members[j];
             connect.group = fill;
             members[i]->connecting_members[members[j]->member_id] = connect;
             connect.dst = members[i];
             members[j]->connecting_members[members[i]->member_id] = connect;
             break;
           }
        }
        if(l == members[j]->groups.size()){
          l = l-1;
        }
        if(members[i]->groups[k]->group_id == members[j]->groups[l]->group_id){
          break;
        }
      }
    }
  }
}

/*
class myComparator
{
  public:
    double operator()(const Member* p1, const Member* p2){
      std::cout << "Comparator called" << "\n";
      return p1->key > p2->key;
    }
};
*/

double Database::BestGroupsToJoin(Member *root) {
  // Fill in your code here
  for (unsigned int i = 0; i < members.size(); i++){
    members[i]->key = std::numeric_limits<int>::max()/2;
    members[i]->parent = NULL;
    members[i]->color = COLOR_WHITE;
  }
  root->key = 0;
  //std::priority_queue<Member *, std::vector<Member * >,myComparator > Q;
  std::vector<Member *> Q;
  
  for(unsigned int i = 0; i < members.size(); i++){
    Q.push_back(members[i]);
  }
  
  Member * u;
  unsigned int i;
  int j;
  while(!Q.empty()){
    int min = std::numeric_limits<int>::max();
    for(i = 0; i < Q.size(); i++){
      if(min > Q[i]->key){
        min = Q[i]->key;
        u=Q[i];
        j = i;
      }
    }
    Q.erase(Q.begin()+j);
    u->color = COLOR_BLACK;
    for (auto it = u->connecting_members.begin(); it != u->connecting_members.end(); ++it ){
        Member * v = it->second.dst;
        if((v->color != COLOR_BLACK) && it->second.GetWeight() < v->key){
          v->parent = u;
          v->key = it->second.GetWeight();
        }
    }
  }
  
  double sum = 0;
  for(unsigned int i = 0; i < members.size(); i++){
    sum = sum + members[i]->key;
  }
  
  return sum;
}

}
