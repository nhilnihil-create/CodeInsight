#include<iostream>
#include<string>
#include<numeric>
#include<set>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
typedef long long li;
#define minimize(a,b) (a>(b)?a=(b),1:0)
#define maximize(a,b) (a<(b)?a=(b),1:0)
#define ceil(a,b) (((a)+(b)-1)/(b))
#define yn(i) print((i)?"Yes":"No")
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




string key="keyence";

void add(char m,string s,set<string> st){
  int n=s.size();
  rep(i,n){
    if(s[i]!=m) continue;
    string t;
    repa(j,i,n){
      t.push_back(s[j]);
      st.insert(t);
    }
  }
}

int gcd(int a,int b){
  return b?gcd(b,a%b):a;
}

int legal(string s,string t,int k){
  int n=s.size();
  repa(i,k,n){
    if(s[i]!=t[i-k]) return 0;
  }
  return 1;
}

string merge(string s,string t,int k){
  int n=s.size();
  string ret;
  rep(i,k) ret.push_back(s[i]);
  rep(i,n) ret.push_back(t[i]);
  return ret;
}


int main(){
  li n; cin >>n;
  string s,t; cin >>s >>t;
  rep(i,n){
    if(legal(s,t,i)){
      string q=merge(s,t,i);
      print(q.size());
      return 0;
    } 
  }
  print(2*n);
}



