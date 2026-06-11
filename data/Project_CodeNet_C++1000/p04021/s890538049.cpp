#include<iostream>
#include<set>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long li;
#define repa(i,a,n) for(int i=(a);i<(n);i++)
#define yn(i) print((i)?"Yes":"No")
#define rep(i,n) for(int i=0;i<(n);i++)

#define df 0
template<class T> void print(const T& t){ cout << t << "\n"; }
template<class T, class... Ts> void print(const T& t, const Ts&... ts) { cout << t; if (sizeof...(ts)) cout << " "; print(ts...); }
// pair 型
template<class S,class T>
std::ostream& operator<<(std::ostream& os, const pair<T,S>& p){
  cout << "(" << p.first << "," << p.second << ")";
  return os;
}

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
// map 型
template<class S,class T>
std::ostream& operator<<(std::ostream& os, const map<S,T>& mp){
  for(const pair<S,T>& x: mp){
    cout << "[" << x.first << "]=" << x.second << " ";
  }
  return os;
}

int main(){
  int n; cin >>n;
  vector<li> a(n);
  rep(i,n) cin >>a[i];
  map<li,int> dict;
  rep(i,n){
    dict[a[i]]++;
  }
  int i=0;
  for(auto& x:dict){
    x.second=i++;
    if(df)print(x);
  }
  if(df) print(dict);
  rep(i,n){
    a[i]=dict[a[i]];
  }
  if(df)print(a);
  int f=0,cnt=0;
  rep(i,n){
    if(df)print(a[i],f);
    if((a[i]^f)&1) cnt++;
    f^=1;
  }
  print(cnt/2);
}



