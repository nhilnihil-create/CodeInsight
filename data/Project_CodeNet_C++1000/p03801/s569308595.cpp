#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> PP;
#define MOD 1000000007
//#define MOD 998244353
#define INF 2305843009213693951
//#define INF 810114514
#define PI 3.141592653589
#define setdouble setprecision
#define REP(i,n) for(ll i=0;i<(n);++i)
#define OREP(i,n) for(ll i=1;i<=(n);++i)
#define RREP(i,n) for(ll i=(n)-1;i>=0;--i)
#define all1(i) begin(i),end(i)
#define GOODBYE do { cout << "-1" << endl; return 0; } while (false)
#define MM <<" "<<
#define Endl endl
#define debug false
#define debug2 false

int main(void){
    
    ll N,a;
    vector<pair<ll,ll>> A;
    cin >> N;
    REP(i,N){
        cin >> a;
        A.push_back({a,i});
    }
    sort(A.begin(),A.end(),greater<>());
    
    //REP(i,N){cout << A[i].first << " " << A[i].second+1 << endl;}
    
    A.push_back({0,-1});
    
    vector<ll> Ans(N,0);
    ll index=INF;
    
    REP(i,N){
        index = min(index,A[i].second);
        Ans[index]+=(A[i].first-A[i+1].first)*(i+1);
    }
    
    REP(i,N){
        cout << Ans[i] << endl;
    }
    
    return 0;
}

