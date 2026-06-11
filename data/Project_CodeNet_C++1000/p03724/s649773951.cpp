#include<iostream>
#include<vector>
using namespace std;
typedef long long li;
#define yn(i) print((i)?"YES":"NO")
#define rep(i,n) for(int i=0;i<(n);i++)
#define df 0
template<class T> void print(const T& t){ cout << t << "\n"; }
template<class T, class... Ts> void print(const T& t, const Ts&... ts) { cout << t; if (sizeof...(ts)) cout << " "; print(ts...); }

int main(){
  int n,m; cin >>n >>m;
  vector<li> cnt(n,0);
  rep(i,m){
    int a,b; cin >>a >>b; a--;b--;
    cnt[a]++; cnt[b]++;
  }
  int flag=1;
  rep(i,n) if(cnt[i]%2==1){
    flag=0;
    break;
  }
  yn(flag);
}
