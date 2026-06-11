#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000

deque<int> deq;
vector<int> G[100010];
bool isvisit[100010];
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    rep(i, M) {
        int s, t;
        cin >> s >> t;
        s--; t--;
        G[s].push_back(t);
        G[t].push_back(s);
    }
    deq.push_back(0);
    
    while(true) {
        int k = deq.back();
        isvisit[k] = true;
        bool isupdate = false;
        for(auto to: G[k]) {
            if(isvisit[to]) continue;
            isupdate = true;
            deq.push_back(to);
            break;
        }
        if(!isupdate) break;
    }
    while(true) {
        int k = deq.front();
        isvisit[k] = true;
        bool isupdate = false;
        for(auto to: G[k]) {
            if(isvisit[to]) continue;
            isupdate = true;
            deq.push_front(to);
            break;
        }
        if(!isupdate) break;
    }
    cout << deq.size() << endl;
    rep(i, deq.size()) {
        if (i != 0) cout << " ";
        cout << deq[i] + 1;
    }
    cout << endl;

    return 0;
}
