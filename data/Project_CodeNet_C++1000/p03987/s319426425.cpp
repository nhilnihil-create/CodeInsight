#include<iostream>
#include<vector>
#include<set>
using namespace std;
typedef long long li;
#define rep(i,n) for(int i=0;i<(n);i++)
#define df 0
template<class T> void print(const T& t){ cout << t << "\n"; }
template<class T, class... Ts> void print(const T& t, const Ts&... ts) { cout << t; if (sizeof...(ts)) cout << " "; print(ts...); }

int main(){
  int n; cin >>n;
  vector<li> a(n),pos(n);
  rep(i,n){
    int t; cin >>t;
    a[i]=t;
    pos[t-1]=i;
  }
  li s=0;
  set<int> st;
  st.insert(-1); st.insert(n);
  rep(i,n){
    auto itr=st.upper_bound(pos[i]);
    li next=*itr; itr--;
    li prev=*itr;
    if(df)print(i+1,prev,pos[i],next);
    s+=(i+1)*(next-pos[i])*(pos[i]-prev);
    st.insert(pos[i]);
  }
  print(s);
}
