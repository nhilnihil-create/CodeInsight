// I SELL YOU...! 
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<chrono>
#include<iomanip>
#include<map>
#include<set>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
void init_io(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << setprecision(10);
}
vector<ll> a(110000,0);
ll n;
string s;
ll next_i(ll i){
  ll res;
  //sheep
  if(a[i]==0){
    if(s[i]=='o'){
      res = a[i-1];
    }else{
      res = !a[i-1];
    }
    //wolf
  }else{
    if(s[i]=='o'){
      res = !a[i-1];
    }else{
      res = a[i-1];
    }
  }
  return res;
}
bool check_i(ll i){
  bool res = true;
  if(a[i]==0){
    if(s[i]=='o'&&a[(i+1)%n]!=a[(i+n-1)%n]){
      res = false;
    }else if(s[i]=='x'&&a[(i+1)%n]==a[(i+n-1)%n]){
      res = false;
    }
  }else{
    if(s[i]=='o'&&a[(i+1)%n]==a[(i+n-1)%n]){
      res = false;
    }else if(s[i]=='x'&&a[(i+1)%n]!=a[(i+n-1)%n]){
      res = false;
    }
  }
  return res;
}
signed main(){
  init_io();
  cin >> n >> s;
  for(int x=0;x<2;x++){
    for(int y=0;y<2;y++){
      a[0] = x;
      a[1] = y;
      for(int i=1;i<n-1;i++){
        a[i+1] = next_i(i);
      }
      bool is_ans=true;
      is_ans &= check_i(0);
      is_ans &= check_i(n-1);
      if(is_ans){
        for(int i=0;i<n;i++){
          if(a[i]==0) cout <<"S";
          else cout <<"W";
        }
        cout << endl;
        return 0;
      }
    }
  }
  cout << "-1\n";
}
