#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;
vector<pair<int64_t,int64_t>>prime_factorize(int64_t x){
  vector<pair<int64_t,int64_t>>p;
  for(int64_t i=2;i*i<=x;i++){
    int cnt=0;
    if(x%i==0){
    while(x%i==0){cnt++;x/=i;}
    p.push_back(make_pair(i,cnt));
    }
  }
  if(x!=1){p.push_back(make_pair(x,1));}
  return p; 
}

int main() {
  int H,W;
  cin>>H>>W;
  vector<string>a(H);
  for(int i=0;i<H;i++){
    cin>>a[i];
  }
  map<char,int>k;
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      k[a[i][j]]++;
    }
  }
  map<int,int>M;
  for(auto c:k){
    M[c.second%4]++;
  }

  bool ok=true;
  if(H%2==0&&W%2==0){
    for(auto c:k){
      if(c.second%4!=0){
        ok=false;
      }
    }
  }
  else if(H%2+W%2==1){
    int even=0;
    if(H%2!=0){even=W;}
    else{even=H;}
    
    if(M[1]||M[3]){ok=false;}
    if(M[2]>even/2){ok=false;}
  }
  else{
    if(M[3]>0){ok=false;}
    if(M[1]!=1){ok=false;}
    if(M[2]>(H-1)/2+(W-1)/2){ok=false;}
  }

  if(ok){cout<<"Yes"<<endl;}
  else{cout<<"No"<<endl;}
  return 0;
}