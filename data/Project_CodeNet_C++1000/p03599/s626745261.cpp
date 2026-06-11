#include<iostream>
using namespace std;
typedef long long li;
#define S_MAX 100000
#define rep(i,n) for(int i=0;i<(n);i++)
#define df 0
template<class T> void print(const T& t){ cout << t << "\n"; }
template<class T, class... Ts> void print(const T& t, const Ts&... ts) { cout << t; if (sizeof...(ts)) cout << " "; print(ts...); }



int main(){
  int a,b,c,d,e,f; cin >>a >>b >>c >>d >>e >>f;
  int tpw=1,tps=0;
  rep(x,30){
    li sum=x*a*100;
    if(sum>f)break;
    rep(y,30){
      sum=(x*a+y*b)*100;
      if(sum>f)break;
      rep(z,S_MAX){
        sum=(x*a+y*b)*100+z*c;
        if(sum>f)break;
        if(c*z>(a*x+b*y)*e) break;
        rep(w,S_MAX){
          sum=(x*a+y*b)*100+z*c+w*d;
          if(sum>f)break;
          if(c*z+d*w>(a*x+b*y)*e) break;
          li s=c*z+d*w,wa=(a*x+b*y)*100;
          if((double)tps/(tps+tpw) <=(double)s/(s+wa)){
            tps=s; tpw=wa;
          }
        }
      }
    }
  }
  print(tpw+tps,tps);
}
