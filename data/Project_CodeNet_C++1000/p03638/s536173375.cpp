// I SELL YOU...! 
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
signed main(){
  ll h,w,n,x=0,y=0;
  bool prev=true;
  cin >> h >> w >> n;
  ll a[n];
  ll grid[h][w];
  P v;
  v.first = v.second = 0;
  queue<P> que;
  for(int i=0;i<n;i++){
    cin >> a[i];
    que.push(P(i+1,a[i]));
  }
  for(int i=0;i<h*w;i++){
    if(v.second==0){
      v = que.front();
      que.pop();
    }
    v.second--;
    grid[y][x] = v.first;
    if((x==w-1 || x == 0)&&!prev){
      y++;
      prev = true;
    }else{
      if(y%2==0) x++;
      else x--;
      prev = false;
    }
  }
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cout << grid[i][j]<<" ";
    }
    cout << endl;
  }
}
