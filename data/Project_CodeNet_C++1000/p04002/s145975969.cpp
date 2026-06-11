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

using namespace std;
int MOD = 1000000007;


signed main(){
    int h,w,n;
    cin >> h >> w >> n;
    
    map<pair<int,int>,int> m;
    rep(i,n){
        int a,b;
        cin >> a >> b;
        for(int x = -1;x <= 1;x++){
            for(int y = -1;y <= 1;y++){
                if(a+x <= 1 || a+x >= h || b+y <= 1 || b+y >= w)continue;
                m[MP(a+x,b+y)]++;
            }
        }
    }
    int all = 0;
    int cnt[10] = {0};
    for(auto p:m){
        cnt[p.se]++;
        all++;
    }
    cout << (h-2)*(w-2) - all << endl;
    for(int i = 1;i <= 9;i++) cout << cnt[i] << endl;
    

    return 0;   
}
// g++ -std=c++14 code1.cpp
// rm -r -f test;oj dl https://ddcc2019-final.contest.atcoder.jp/tasks/ddcc2019_final_a
// rm -r -f test;oj dl http://arc060.contest.atcoder.jp/tasks/arc060_a