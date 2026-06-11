#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(){
  int N,M;
  set<int> ball_prob={1};
  int from,to;
  cin >> N >> M;
  vector<int> ball_num(N,1);

  for(int i=0;i<M;i++){
    cin >> from >> to;
    auto it = ball_prob.find(from);
    if(it!=ball_prob.end()){
      ball_prob.insert(to);
    }
    ball_num.at(from-1)--;
    ball_num.at(to-1)++;
    if(ball_num.at(from-1)==0){
      auto it = ball_prob.find(from);
      if(it!=ball_prob.end()){
        ball_prob.erase(from);
      }
    }
  }
  cout << ball_prob.size() << endl;
}