#include "bits/stdc++.h"
typedef long long ll;
#define int ll
#define fi first
#define se second
#define SORT(a) sort(a.begin(),a.end())
#define rep(i,n) for(int i = 0;i < (n) ; i++) 
#define REP(i,n) for(int i = 0;i < (n) ; i++)
#define MP(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define INF LLONG_MAX/2
#define all(x) (x).begin(),(x).end()
#define debug(x) cerr<<#x<<": "<<x<<endl
#define debug_vec(v) cerr<<#v<<":";rep(i,v.size())cerr<<" "<<v[i];cerr<<endl
using namespace std;
int MOD = 1000000007;
int h,w,H,W;
int m[501][501];

signed main(){
    
    cin >> H >> W >> h >> w;
    if(H%h == 0 && W%w == 0){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;


    if(W%w != 0){
        rep(i,H){
            rep(j,W){
                int a = 0;
                if(j%w == 0)a = 1000;
                else if(j%w == w-1)a = -1001;
                cout << a << " ";
            }
            cout << endl;
        }
    }else{
        rep(i,H){
            rep(j,W){
                int a = 0;
                if(i%h == 0)a = 1000;
                else if(i%h == h-1)a = -1001;
                cout << a << " ";
            }
            cout << endl;
        }
    }
    
    return 0; 
}

// g++ -std=c++14 code1.cpp
// rm -r -f test;oj dl https://yahoo-procon2019-qual.contest.atcoder.jp/tasks/yahoo_procon2019_qual_d
// rm -r -f test;oj dl http://agc016.contest.atcoder.jp/tasks/agc016_c