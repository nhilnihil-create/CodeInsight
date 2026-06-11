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
    vector<int> p(n);
    rep(i,n){
        int a,b;
        cin >> a >> b;
        p[i] = a + (h+1)*b;
    }
    SORT(p);
    int cnt[10] = {0};
    rep(i,n){
        for(int x = -1;x <= 1;x++){
            for(int y = -1;y <= 1;y++){
                int X = p[i]%(h+1);
                int Y = p[i]/(h+1);
                if(X+x <= 1 || X+x >= h || Y+y <= 1 || Y+y >= w) continue;
                int c = 0;
                auto a1 = lower_bound(p.begin(),p.end(),(X+x-1) + (h+1)*(Y+y-1));
                auto b1 = upper_bound(p.begin(),p.end(),(X+x+1) + (h+1)*(Y+y-1));
                int c1 = distance(a1,b1);
                auto a2 = lower_bound(p.begin(),p.end(),(X+x-1) + (h+1)*(Y+y));
                auto b2 = upper_bound(p.begin(),p.end(),(X+x+1) + (h+1)*(Y+y));
                int c2 = distance(a2,b2);
                auto a3 = lower_bound(p.begin(),p.end(),(X+x-1) + (h+1)*(Y+y+1));
                auto b3 = upper_bound(p.begin(),p.end(),(X+x+1) + (h+1)*(Y+y+1));
                int c3 = distance(a3,b3);
                cnt[c1+c2+c3]++;
                //cerr << X << " " << Y << " " << x << " " << y << " " << c1+c2+c3 << endl;
            }
        }
    }
    cout << (h-2)*(w-2) - cnt[1]-cnt[2]/2-cnt[3]/3-cnt[4]/4-cnt[5]/5-cnt[6]/6-cnt[7]/7-cnt[8]/8-cnt[9]/9 << endl;
    for(int i = 1 ;i <= 9;i++){
        cout << cnt[i]/i << endl;
    }

    return 0;   
}
// g++ -std=c++14 code1.cpp
// rm -r -f test;oj dl https://ddcc2019-final.contest.atcoder.jp/tasks/ddcc2019_final_a
// rm -r -f test;oj dl http://arc060.contest.atcoder.jp/tasks/arc060_a