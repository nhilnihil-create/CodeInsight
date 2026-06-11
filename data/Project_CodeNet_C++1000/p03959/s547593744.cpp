#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <iomanip>
#include <map>
#include <set>
#include <cmath>
#include <cstdio>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define FOR(i,m,n) for(int (i)=(m);(i)<(n);(i)++)
#define All(v) (v).begin(),(v).end()
typedef long long ll;

int main(){
    int N;cin >> N;
    vector<int> T(N),A(N);
    rep(i,N)cin >> T[i];
    rep(i,N)cin >> A[i];
    using pii = pair<int,int>;//区間なら１、値なら０
    vector<pii> t(N),a(N);
    t[0]=make_pair(0,T[0]);
    for(int i=1;i<N;i++){
        int b = T[i-1]==T[i]?1:0;
        t[i]=make_pair(b,T[i]);
    }
    a[N-1]=make_pair(0,A[N-1]);
    for(int i=N-2;i>=0;i--){
        int b = A[i+1]==A[i]?1:0;
        a[i]=make_pair(b,A[i]);
    }
    ll res = 1;
    rep(i,N){
        int tf=t[i].first,af=a[i].first,ts=t[i].second,as=a[i].second;
        if(tf==0&&af==0){
            if(ts!=as)res*=0;
        }else if((tf==1&&af==0)){
            if(ts<as)res*=0;
        }else if(tf==0&&af==1){
            if(ts>as)res*=0;
        }else{
            res=res*min(ts,as)%(1000000007);
        }
    }
    cout << res << endl;
    return 0;
}