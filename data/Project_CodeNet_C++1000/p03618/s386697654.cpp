#include<iostream>
#include<vector>
using namespace std;
typedef long long li;
#define rep(i,n) for(int i=0;i<(n);i++)
#define df 0
template<class T> void print(const T& t){ cout << t << "\n"; }
template<class T, class... Ts> void print(const T& t, const Ts&... ts) { cout << t; if (sizeof...(ts)) cout << " "; print(ts...); }

int main(){
  string a; cin >>a;
  vector<int> cnt(26,0);
  int s=0,n=a.size();
  li ans=1;
  rep(i,n){
    ans+=s-cnt[a[i]-'a'];
    s++; cnt[a[i]-'a']++;
  }
  print(ans);
}
