#include<bits/stdc++.h>
using namespace std;

#define lint long long
#define P pair<int, int>
#define LLP pair<long long, long long>
#define REP(i, x, n) for(int i = (x), i##_len = (int)(n) ; i < i##_len ; ++i)
#define rep(i, n) for(int i = 0, i##_len = (int)(n) ; i < i##_len ; ++i)
#define reps(i, n) for(int i = 1, i##_len = (int)(n) ; i <= i##_len ; ++i)
#define rrep(i, n) for(int i = (int)(n) - 1 ; i >= 0 ; --i)
#define rreps(i, n) for(int i = (int)(n) ; i > 0 ; --i)
#define SORT(x) sort((x).begin(), (x).end())
#define SORT_INV(x) sort((x).rbegin(), (x).rend())

const int IINF = (1 << 30) - 1;
const long long LLINF = 1LL << 61;
const long long MOD = 1000000007LL;
const int dx4[] = {1, 0, -1, 0}, dy4[] = {0, 1, 0, -1};
const int dx8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy8[] = {0, -1, -1, -1, 0, 1, 1, 1};
const double EPS = 1e-8;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    lint w, h;
    cin >> w >> h;

    vector< LLP > pq(w + h);
    rep(i, w){
        cin >> pq[i].first;
        pq[i].second = 0;
    }
    REP(i, w, w + h){
        cin >> pq[i].first;
        pq[i].second = 1;
    }
    SORT(pq);

    lint ans = 0;
    rep(i, w + h){
        if(pq[i].second == 0){
            ans += max(pq[i].first * (h + 1LL), 0LL);
            --w;
        }else{
            ans += max(pq[i].first * (w + 1LL), 0LL);
            --h;
        }
    }

    cout << ans << endl;

    return 0;
}