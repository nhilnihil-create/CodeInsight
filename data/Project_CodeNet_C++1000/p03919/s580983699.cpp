#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
#include<cmath>
#include<bitset>
#define ll long long
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FFOR(i,a,b) for(int i=(a);i<=(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define RREP(i,n)  FFOR(i,0,n)
#define SORT(V) sort((V).begin(),(V).end())
#define INF ((1LL<<62)-(1LL<<31))
#define MOD 1000000007
using namespace std;

int main(){
  int H,W;
  cin>>H>>W;
  string S[H+1][W+1];
  
  REP(i,H){
    REP(j,W){
      cin>>S[i][j];
      if(S[i][j]=="snuke") cout<<char(j+'A')<<i+1<<endl;
    }
  }
  
}
