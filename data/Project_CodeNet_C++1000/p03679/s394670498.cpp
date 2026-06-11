#include<iostream>
#include<numeric>
#include<set>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
typedef long long li;
#define chmin(a,b) (a>(b)?a=(b),1:0)
#define abs(n) max((n),-(n))
#define dist(a,b) max((a)-(b),(b)-(a))
#define chmax(a,b) (a<(b)?a=(b),1:0)
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
  int x,a,b; cin >>x >>a >>b;
  if(a>=b) print("delicious");
  else if(a+x>=b) print("safe");
  else print("dangerous");
}


