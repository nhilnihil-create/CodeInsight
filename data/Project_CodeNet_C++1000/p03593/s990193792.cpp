#include<iostream>
#include<vector>
using namespace std;
typedef long long li;
#define yn(i) print((i)?"Yes":"No")
#define rep(i,n) for(int i=0;i<(n);i++)
#define df 0
template<class T> void print(const T& t){ cout << t << "\n"; }
template<class T, class... Ts> void print(const T& t, const Ts&... ts) { cout << t; if (sizeof...(ts)) cout << " "; print(ts...); }
// Container コンテナ型, map以外
template< template<class ...> class Ctn,class T>
std::ostream& operator<<(std::ostream& os,const Ctn<T>& v){
  auto itr=v.begin();
  while(itr!=v.end()){
    if(itr!=v.begin())cout << " ";
    cout << *(itr++);
  }
  return os;
}

int main(){
  int h,w; cin >>h >>w;
  vector<string> vs(h);
  rep(i,h) cin >>vs[i];
  vector<int> cnt(26,0);
  rep(i,h) rep(j,w) cnt[vs[i][j]-'a']++;
  if(df)print(cnt);
  vector<int> md(4,0);
  rep(i,26){
    md[cnt[i]%4]++;
  }
  if(df)print(md);
  int flag=(md[1]+md[3]<=1),border=h%2*w/2+w%2*h/2;
  if(md[2]+md[3]>border) flag=0;
  yn(flag);
}
