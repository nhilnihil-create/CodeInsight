#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

int main(){
  int K, T;
  vector<int>vec;
  cin >> K >> T;
  priority_queue<int>que;
  for(int i = 0 ; i < T ; i++){
    int t; cin >> t;
    que.push(t);
  }
  while(que.size() > 1){
    int x = que.top();
    que.pop();
    int y = que.top();
    que.pop();
    x--;
    y--;
    if(x)que.push(x);
    if(y)que.push(y);
  }
  cout << que.top() - 1 << endl;
  return 0;
}
