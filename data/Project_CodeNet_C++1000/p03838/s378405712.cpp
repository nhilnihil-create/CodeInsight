#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define vi vector<int>
#define all(x) (x).begin(),(x).end()
#define INF (1<<30)-1
using ll = long long;
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(b<a) { a=b; return 1; } return 0; }

int main(){
  int x,y; cin >> x >> y;

  int ans1 = INF, ans2 = INF, ans3 = INF;
  if(x < y){
    ans1 = y - x;
  }else{
    if(0 <= x && 0 <= y && -x < y){
      if(y) ans2 = x + y;
      else ans2 = x + y + 1;
    }
  }

  if(x < 0 && y < 0){
    ans3 = 2;
    x *= -1;
    y *= -1;
  }else if(x < 0){
    ans3 = 1;
    x *= -1;
  }else if(y < 0){
    ans3 = 1;
    y *= -1;
  }
  ans3 += abs(x-y);

  cout << min({ans1,ans2,ans3});
  cout << "\n";
  return 0;
}
