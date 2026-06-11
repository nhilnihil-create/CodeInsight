#include<iostream>
#include<vector>
using namespace std;
typedef long long li;
#define rep(i,n) for(int i=0;i<(n);i++)
#define df 0
template<class T> void print(const vector<T>& v){
  for(const T& t: v)
  cout << t << " ";
  cout << "\n";
}
template<class T> void print(const T& t){ cout << t << "\n"; }
template<class T, class... Ts> void print(const T& t, const Ts&... ts) { cout << t; if (sizeof...(ts)) cout << " "; print(ts...); }

int main(){
  int n; cin >>n;
  vector<int> a(n),b(n);
  rep(i,n){
    a[i]=i+1; b[i]=n-i;
    a[i]*=n;  b[i]*=n;
  }
  rep(i,n){
    int p; cin >>p;
    a[p-1]+=i;
  }
  print(a);
  print(b);
}
