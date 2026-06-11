#include <bits/stdc++.h>
using namespace std;
#define FOR(i,l,n) for(size_t i=l; i<(int)(n); ++i)
#define REP(i,n) FOR(i,0,n)
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vvi = vector<vi>;
using mii = map<int,int>;
using pii = pair<int,int>;
using ti3 = tuple<int,int,int>;

int main(){
  int a,b,c; cin>>a>>b>>c;
  int a_i=a, b_i=b, c_i=c;

  if(a_i%2+b_i%2+c_i%2!=0){
    cout<<"0"<<endl;    
    return 0;
  }
  
  REP(i,30){
    a_i = (a+b+c-a_i)/2;
    b_i = (a+b+c-b_i)/2;
    c_i = (a+b+c-c_i)/2;
    if(a_i%2+b_i%2+c_i%2!=0){
      cout<<i+1<<endl;    
      return 0;
    }
  }
  cout<<"-1"<<endl;
}