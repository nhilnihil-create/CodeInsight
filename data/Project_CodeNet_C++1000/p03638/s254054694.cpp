#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i < n+1; i++)
#define sort(A) sort(A.begin(),A.end())
#define reverse(A) reverse(A.begin(),A.end());

typedef long long ll;

int main(){
  int h,w;
  cin >> h >> w;
  vector<vector<int>> maze(h+2,vector<int>(w+2,0));
  int n;
  cin >> n;
  queue<int> q;
  rep(i,n){
    int x;
    cin >> x;
    rep(j,x) q.push(i+1);
  }
  stack<pair<int,int>> s;
  s.push(make_pair(1,1));
  while(!s.empty()){
    int x = s.top().first;
    int y = s.top().second;
    s.pop();
    if(maze[x][y]>0) continue;
    if(x<1 || x>h) continue;
    if(y<1 || y>w) continue;
    maze[x][y] = q.front();
    q.pop();
    if(maze[x][y+1] == 0) s.push(make_pair(x,y+1));
    if(maze[x-1][y] == 0) s.push(make_pair(x-1,y));
    if(maze[x+1][y] == 0) s.push(make_pair(x+1,y));
  }//while
  rep1(i,h){
    rep1(j,w) cout << maze[i][j] << " ";
    cout << endl;
  }
}