#include<bits/stdc++.h>
using namespace std;
#define inf 1e9
#define ll long long 
#define M 1000000007
#define P pair<int,int>
#define FOR(i,m,n) for(int i=m;i<n;i++)
#define rep(i,n) FOR(i,0,n)
const int vx[4] = {0,1,0,-1};
const int vy[4] = {1,0,-1,0};
#define PI 3.14159265

int h,w;
string s[30][30];

int main(){
  cin>>h>>w;
  rep(i,h){
    rep(j,w){
      cin>>s[i][j];
    }
  }

  char ansh;
  int answ;

  rep(i,h){
    rep(j,w){
      if(s[i][j]=="snuke"){
        ansh=(char)(j+'A');
        answ=i+1;
      }
    }
  }
  
  cout<<ansh<<answ<<endl;

  return 0;
}
