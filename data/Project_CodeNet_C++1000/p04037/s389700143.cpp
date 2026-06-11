#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long li;
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

// map 型
template<class S,class T>
std::ostream& operator<<(std::ostream& os, const map<S,T,greater<li>>& mp){
  for(const pair<S,T>& x: mp){
    cout << "[" << x.first << "]=" << x.second << " ";
  }
  return os;
}

int main(){
  int n; cin >>n;
  map<li,int,greater<li>> mp;
  rep(i,n){
    li a; cin >>a; mp[a]++;
  }
  if(df)print(mp);
  auto itr=mp.begin();
  int flag=(itr->first+itr->second)%2;
  int s=itr->second,temp=itr->first;
  mp.erase(itr);
  for(pair<li,int> p: mp){
    if(df)print("p:",p);
    if((temp^p.first^p.second)&1){
      int y=s+(1-(p.second&1));
      if(df)print("s,y:",s,y);
      if(y<=p.first) flag^=1;
      if(df)print(flag);
    }
    s+=p.second;
    temp=p.first;
  }
  
  printf("%s\n",flag?"First":"Second");
}
