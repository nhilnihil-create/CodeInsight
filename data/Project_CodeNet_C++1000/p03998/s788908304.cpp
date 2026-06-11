#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define all(x) x.begin(),x.end()
#define rep(i,j,n) for (long long i = j; i < (long long)(n); i++)
#define _GLIBCXX_DEBUG
#define MOD 1000000007
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//(a+b-1)/b

signed main(){
	string a,b,c; cin>>a>>b>>c;
  reverse(all(a));
  reverse(all(b));
  reverse(all(c));
  char k='a';
  char ans;
  while(true){
    if(k=='a'){
      if(a.empty()){
        ans='A';
        break;
      }
      k=a[a.size()-1];
      a.pop_back();
    }
    else if(k=='b'){
      if(b.empty()){
        ans='B';
        break;
      }
      k=b[b.size()-1];
      b.pop_back();
    }
    else{
      if(c.empty()){
        ans='C';
        break;
      }
      k=c[c.size()-1];
      c.pop_back();
    }
  }
    cout<<ans<<endl;
      
    
  
	
	
	return 0;
}