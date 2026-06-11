#include <bits/stdc++.h>
using namespace std;

int main(){
  int x,y;
  cin >> x >> y;
  priority_queue<int,vector<int>,greater<int> > pq;
  if(x<=y){
    pq.push(y-x);
  }
  if(-x<=y){
    pq.push(y+x+1);
  }
  if(x<=-y){
    pq.push(-y-x+1);
  }
  if(-x<=-y){
    pq.push(-y+x+2);
  }
  cout << pq.top() << endl;
  return 0;
}
