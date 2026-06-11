#include <bits/stdc++.h>
using namespace std;

using int32 = int_fast32_t;
using int64 = int_fast64_t;

const int32 INF = 1e9;
const int32 MOD = 1e9+7;
const int64 LLINF = 1e18;

#define YES(n) cout << ((n) ? "YES\n" : "NO\n"  )
#define Yes(n) cout << ((n) ? "Yes\n" : "No\n"  )
#define ANS(n) cout << (n) << "\n"
#define REP(i,n) for(int64 i=0;i<(n);++i)
#define FOR(i,a,b) for(int64 i=(a);i<(b);i++)
#define FORR(i,a,b) for(int64 i=(a);i>=(b);i--)
#define ALL(obj) (obj).begin(),(obj).end()
#define pii pair<int32,int32>
#define pll pair<int64,int64>
#define pb(a) push_back(a)
#define mp make_pair

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int32 n,m;
    cin >> n >> m;
    map<int32,int32> x;
    REP(i,n){
        int32 xi;
        cin >> xi;
        x[xi]++;
    }
    map<int32,int32> xmodm;
    vector<int32> samepair(m,0);
    for(pii p : x){
        samepair[p.first%m] += p.second / 2;
        xmodm[p.first%m] += p.second;
    }
    int64 ans = 0;
    REP(i,m/2+1){
        if(i * 2 == m || i == 0){
            ans += xmodm[i] / 2;
        }else{
            if(xmodm[i] == xmodm[m-i]){
                ans += xmodm[i];
            }else if(xmodm[i] > xmodm[m-i]){
                ans += xmodm[m-i];
                xmodm[i] -= xmodm[m-i];
                ans += min(xmodm[i] / 2, samepair[i]);
            }else{
                ans += xmodm[i];
                xmodm[m-i] -= xmodm[i];
                ans += min(xmodm[m-i] / 2, samepair[m-i]);
            }
        }
    }
    // ostream_iterator<int32> out_it(cout, " ");
    // copy(ALL(samepair), out_it);
    // cout << endl;
    ANS(ans);
    return 0;
}