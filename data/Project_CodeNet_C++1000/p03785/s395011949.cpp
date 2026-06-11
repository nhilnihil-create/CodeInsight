#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i < n+1; i++)
#define all(A) A.begin(),A.end()
typedef long long ll;

int main(){
  int n,c,k;
  cin >> n >> c >> k;
  vector<int> t(n);
  rep(i,n) cin >> t[i];
  sort(all(t));
  queue<int> q;
  rep(i,n) q.push(t[i]);
  int ans = 0;
  int bus = 0;
  int time = 0;
  while(!q.empty()){
    int now = q.front();
    q.pop();
    //cout << now << ",";
    if(bus == 0 || now > time+k){
      //cout << "new" << endl;
      bus = 1;
      ans ++;
      time = now;
    }else{
      if(bus < c){
        //cout << "ride" << endl;
        bus ++;
      }else{
        //cout << "over" << endl;
        ans ++;
        bus = 1;
        time = now;
      }
    }
  }
  cout << ans << endl;
}