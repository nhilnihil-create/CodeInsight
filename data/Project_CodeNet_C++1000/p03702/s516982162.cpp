#include "bits/stdc++.h"
 
typedef long long ll;
#define int ll
#define fi first
#define se second
#define SORT(a) sort(a.begin(),a.end())
#define REP(i,n) for(int i = 0;i < (n) ; i++) 
#define MP(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define INF LLONG_MAX/2

using namespace std;

int MOD = 1000000007;
int n,a,b,ans;
vector<int> h(100010);

int isok(int k,int h[]){
    int K = k;
    REP(i,n){
        // cerr << (h[i]) << " ";
        if(h[i]-b*k <= 0);
        else if((h[i]-b*k)%(a-b) != 0) K -= (h[i]-b*k)/(a-b) +1;
        else K -= (h[i]-b*k)/(a-b);
    }
    // cerr << " " <<  K;
    if(K >= 0) return 1;
    else return 0;
}

signed main(){

    cin >> n >> a >> b;
    int h[100010];
    REP(i,n){
        cin >> h[i];
        // cerr << h[i] <<" ";
    }
    sort(h,h+n);

    int ok = 1000000001;//解が存在
    int ng = 0;//解が存在しない
    while(abs(ok - ng) > 1){
        int mid = (ok + ng)/2;
        // cerr << mid;
        if(isok(mid,h)) {ok = mid; }
        else {ng = mid;}
    }

    cout << ok << endl;

    return 0;
}
// g++ -std=c++14 code1.cpp
// rm -r -f test;oj dl 