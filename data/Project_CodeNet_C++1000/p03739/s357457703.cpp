#include<iostream>
#include<vector>
using namespace std;
typedef long long li;
#define rep(i,n) for(int i=0;i<(n);i++)
#define df 0
template<class T> void print(const T& t){ cout << t << "\n"; }
template<class T, class... Ts> void print(const T& t, const Ts&... ts) { cout << t; if (sizeof...(ts)) cout << " "; print(ts...); }

int main(){
  int n; cin >>n;
  vector<li> s(2,0),c(2,0);
  rep(i,n){
    li a; cin >>a;
    rep(j,2){
      s[j]+=a;
      if((i+j)%2){
        if(s[j]>=0){
          c[j]+=s[j]+1;
          s[j]=-1;
        }
      }else{
        if(s[j]<=0){
          c[j]+=-s[j]+1;
          s[j]=1;
        }
      }
    }
  }
  print(min(c[0],c[1]));
}
