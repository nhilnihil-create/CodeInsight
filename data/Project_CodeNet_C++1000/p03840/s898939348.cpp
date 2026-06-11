#include<iostream>
#include<vector>
using namespace std;
typedef long long li;
#define rep(i,n) for(int i=0;i<(n);i++)
#define df 0
template<class T> void print(const T& t){ cout << t << "\n"; }
template<class T, class... Ts> void print(const T& t, const Ts&... ts) { cout << t; if (sizeof...(ts)) cout << " "; print(ts...); }

int main(){
  li v[7];
  rep(i,7) cin >> v[i];
  if(df)print(v[0]+v[1]+v[3]+v[4]);
  li s=v[1];
  if(v[0] && v[3] && v[4]){
    int f=(v[0]&1)+(v[3]&1)+(v[4]&1);
    if(f>=2){
      s+=3; v[0]--; v[3]--; v[4]--;      
    }
  }
  s+=v[0]/2*2;
  s+=v[3]/2*2;
  s+=v[4]/2*2;
  print(s);
}
