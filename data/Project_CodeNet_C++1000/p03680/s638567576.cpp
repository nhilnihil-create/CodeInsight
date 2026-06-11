#include<bits/stdc++.h>
using ll=long long;
using namespace std;
#define rep(i, n) for(ll i=0; i<n; i++)
#define Rep(i, j, n) for(ll i=j; i<n; i++)
#define all(vec) vec.begin(), vec.end()
template<class T> inline bool chmin(T& a, T b) {if(a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) {if(a < b) {a = b; return true;} return false;}

int main(){
  int n;
  cin>>n;
  vector<int>a(n);
  vector<int>on(n);
  on[0]=1;
  int tmp;
  int cnt=0;
  rep(i,n){cin>>tmp;tmp--;a[i]=tmp;}
  tmp=a[0];
  rep(i,n){
    if(tmp==1)break;
    else if(on[tmp]==0){
      cnt++;
      on[tmp]=1;
      tmp=a[tmp];
    }
    else{
      cout<<-1<<endl;return 0;
    }
  }
  cnt++;
  cout<<cnt<<endl;
  
  
    
    
  return 0;
}
