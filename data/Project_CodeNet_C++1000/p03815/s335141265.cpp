#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define int long long
 
int myf(int x){
    int ret;
    x==0 ? ret=0:
    x<=6 ? ret=1:
  	ret=2;
    return ret;
}

signed main(){
    int N;
    cin >>N;
    cout<<(N/11)*2+myf(N%11)<<endl;
}