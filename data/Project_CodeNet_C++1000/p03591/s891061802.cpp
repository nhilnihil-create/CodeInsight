#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<cstring>
#include<bitset>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<numeric>
#include<set>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};
static const int N=114514;

#define rep(i,x) for(int i=0;i<x;i++)
#define re(i,x,y) for(int i=x;i<y;i++)

long long INF=1e9;
const long long mod=1e9+7;
#define ll long long

int main(){
  cin.tie(0); ios::sync_with_stdio(false);
  string s;
  cin>>s;
  if(s[0]=='Y'&&s[1]=='A'&&s[2]=='K'&&s[3]=='I'){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
  return 0;
}