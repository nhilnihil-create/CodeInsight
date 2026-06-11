#include <bits/stdc++.h>
using namespace std;
#define FOR(i,l,n) for(int i=l; i<(int)(n); ++i)
#define REP(i,n) FOR(i,0,n)
using ll = long long;

int main() {
  int n,a,b;
  string s;
  cin>>n>>a>>b>>s;
  int cnt_ab=0,cnt_b=0;
  REP(i,n){
    if(s[i]=='a'){
      if(cnt_ab<a+b){
        cnt_ab++;
        cout<<"Yes"<<endl;
      } else {
        cout<<"No"<<endl;
      }
    } else if(s[i]=='b'){
      if(cnt_ab<a+b&&cnt_b<b){
        cnt_ab++;
        cnt_b++;
        cout<<"Yes"<<endl;
      } else {
        cout<<"No"<<endl;
      }
    } else {
      cout<<"No"<<endl;
    }      
  }
}