#include "member.h"

#include <queue>

#include "database.h"
#include <limits>

namespace algdb {

void Member::DumpConnections() {
  std::cout << "(" << member_id << ")";
  for (auto &m : connecting_members) {
    auto conn = m.second;
    std::cout << "->" << conn.dst->member_id << 
      "(" << conn.group->group_id << ")";
  }
  std::cout << "\n";
}

void Member::PathToMemberBFS(uint64_t dst_member_id) {
  // Fill in your code here.
  this->color = COLOR_GRAY;
  this->key = 0;
  this->parent = NULL;
  std::queue<Member *> Q;
	Q.push(this);
	while(!Q.empty()){
	  Member * u = Q.front();
	  Member * v;
		Q.pop();
		for (auto it = u->connecting_members.begin(); it != u->connecting_members.end(); ++it ){
        v = it->second.dst;
        if(v->color == COLOR_WHITE){
          v->color = COLOR_GRAY;
          v->key = u->key + 1;
          v->parent = u;
          Q.push(v);
          if(v->member_id == dst_member_id){
            return;
          }
        }
		}
		u->color = COLOR_BLACK;
		}
}

Member * Member::DLS(Member * node, int depth,uint64_t dst_member_id){
  if((depth == 0) && (node->member_id == dst_member_id)){
    return node;
  }
  if(depth > 0){
		for (auto it = node->connecting_members.begin(); it != node->connecting_members.end(); ++it ){
        Member * v = it->second.dst;
        v->parent = node;
        Member * found = DLS(v,(depth-1),dst_member_id);
        if(found != NULL){
          return found;
        }
		}
  }
  return NULL;
}

void Member::PathToMemberIDDFS(uint64_t dst_member_id) {
  // Fill in your code here
  Member * found;
  for(int depth = 0; depth < std::numeric_limits<int>::max(); depth++){
    found = DLS(this,depth,dst_member_id);
    if(found != NULL){
      return;
    }
  }
}

void Member::PrintPath(Member* dst) {
  Member *curr = dst;
  while(curr && curr != this) {
    std::cout << curr->member_name << " <- ";
    curr = curr->parent;
  }
  std::cout << this->member_name << "\n";
}

}
