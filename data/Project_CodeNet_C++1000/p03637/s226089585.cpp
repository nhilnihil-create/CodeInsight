#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,0,n+1)
#define int long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
const int MOD=1e9+7;
const int INF=1e18;
const int MAX=3000;

signed main(){
    int N;cin>>N;
    int count=0;
  	int xcou=0;
    REP(i,N){
        int a;cin>>a;
        if(a%4==0)count++;
      	else if(a%2==0)xcou++;
    }
  	if(xcou>1)N-=xcou-1;
    cout<<(N/2<=count?"Yes":"No")<<endl;
}
