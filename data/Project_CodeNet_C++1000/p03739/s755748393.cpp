#include<iostream>
using namespace std;
typedef long long li;
#define rep(i,n) for(int i=0;i<(n);i++)
#define df 0
template<class T> void print(const T& t){ cout << t << "\n"; }
template<class T, class... Ts> void print(const T& t, const Ts&... ts) { cout << t; if (sizeof...(ts)) cout << " "; print(ts...); }

int main(){
  int n; cin >>n;
  li p=0,m=0,f=1,pc=0,mc=0;
  rep(i,n){
    li a; cin >>a;
    if(f){         // S>0 in p
      p+=a;
      if(p<=0){
        pc-=p-1;
        p=1;
      }
      m+=a;
      if(m>=0){
        mc+=m+1;
        m=-1;
      }
    }else{
      p+=a;
      if(p>=0){
        pc+=p+1;
        p=-1;
      }
      m+=a;
      if(m<=0){
        mc-=m-1;
        m=1;
      }
    }
    f^=1;
  }
  print(min(pc,mc));
}
