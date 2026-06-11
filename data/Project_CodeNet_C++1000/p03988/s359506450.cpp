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
int n;
int a[101];

signed main(){
    cin >> n;
    int mini = 110;
    int maxi = -1;
    rep(i,n){
        int val;
        cin >> val;
        a[val]++;
        mini = min(mini,val);
        maxi = max(maxi,val);
    }

    if(a[mini] == 1){
        if(maxi != mini*2){
            cout << "Impossible" << endl;
            return 0;
        }
        
        for(int i = mini+1;i <= maxi;i++){
            if(a[i] < 2){
                cout << "Impossible" << endl;
                return 0;
            }
        }
        cout << "Possible" << endl;
    }else if(a[mini] == 2){
        if(maxi != mini*2-1){
            cout << "Impossible" << endl;
            return 0;
        }
        for(int i = mini+1;i <= maxi;i++){
            if(a[i] < 2){
                cout << "Impossible" << endl;
                return 0;
            }
        }
        cout << "Possible" << endl;
    }else{
        cout << "Impossible" << endl;
    }



    

    return 0; 
}

// g++ -std=c++14 code1.cpp
// rm -r -f test;oj dl https://yahoo-procon2019-qual.contest.atcoder.jp/tasks/yahoo_procon2019_qual_d
// rm -r -f test;oj dl http://agc005.contest.atcoder.jp/tasks/agc005_c