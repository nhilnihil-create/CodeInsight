#include<iostream>
#include<numeric>
#include<set>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
typedef long long li;
#define repa(i,a,n) for(int i=(a);i<(n);i++)
#define MOD 1000000000
#define rep(i,n) for(int i=0;i<(n);i++)

#define df 0
template<class T> void print(const T& t){ cout << t << "\n"; }
template<class T, class... Ts> void print(const T& t, const Ts&... ts) { cout << t; if (sizeof...(ts)) cout << " "; print(ts...); }
// Container コンテナ型, map以外
template< template<class ...> class Ctn,class T>
std::ostream& operator<<(std::ostream& os,const Ctn<T>& v){
  // ここでストリームに obj を書き込みます。
  auto itr=v.begin();
  while(itr!=v.end()){
    if(itr!=v.begin())cout << " ";
    cout << *(itr++);
  }
  return os;
}


int main(){
  map<int,int> mp;
  int n,m; cin >>n >>m;
  rep(i,n){
    int a; cin >>a;
    mp[a]++;
  }

  map<int,int> red,pr;
  for(pair<int,int> x: mp){
    pr[x.first%m]+=x.second/2;
    red[x.first%m]+=x.second;
  }
  int cnt=0;
  if(m%2==0){
    cnt+=red[m/2]/2;
    red[m/2]=0;
  }
  cnt+=red[0]/2;
  red[0]=0;
  rep(i,m/2){
    int a=min(red[i+1],red[m-i-1]);
    cnt+=a;
    red[i+1]-=a;
    red[m-i-1]-=a;
  }
  rep(i,m){
    cnt+=min(pr[i],red[i]/2);
  }
  print(cnt);
}

