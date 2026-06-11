#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int INF=1e9;
const int di[] = {-1,0,1,0};
const int dj[] = {0,-1,0,1};

int main() {
  string S;
  cin>>S;
  int n=0;
  int w=0;
  int s=0;
  int e=0;
  rep(i,S.length()){
    if(S[i]=='N') n++;
    if(S[i]=='W') w++;
    if(S[i]=='S') s++;
    if(S[i]=='E') e++;
  }
  bool ja=true;
  if(n>0){
    if(s==0) ja=false;
  }
  if(w>0){
    if(e==0) ja=false;
  }
  if(s>0){
    if(n==0) ja=false;
  }
  if(e>0){
    if(w==0) ja=false;
  }
  if(ja){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
}