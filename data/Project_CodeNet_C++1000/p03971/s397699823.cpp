#include<bits/stdc++.h>
using ll=long long;
using namespace std;
#define rep(i, n) for(ll i=0; i<n; i++)
#define Rep(i, j, n) for(ll i=j; i<n; i++)
#define all(vec) vec.begin(), vec.end()
template<class T> inline bool chmin(T& a, T b) {if(a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) {if(a < b) {a = b; return true;} return false;}

int main(){
  int n,a,b;
  string s;
  cin>>n>>a>>b>>s;
  int tmpa=0;
  int tmpb=0;

  rep(i,n){
    if(s[i]=='c')cout<<"No"<<endl;
    if(s[i]=='a'){
      if(tmpa+tmpb<a+b){
	tmpa++;
	cout<<"Yes"<<endl;
      }else cout<<"No"<<endl;
    }
    if(s[i]=='b'){
      if(tmpa+tmpb<a+b&&tmpb<b){
	tmpb++;
	cout<<"Yes"<<endl;
      }else cout<<"No"<<endl;
    }
  }
    
    
  return 0;
}
