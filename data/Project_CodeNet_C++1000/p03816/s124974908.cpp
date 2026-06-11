#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define FOR(i,s,n) for(int i = s; i < (n); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(n) (n).begin(), (n).end()
#define RALL(n) (n).rbegin(), (n).rend()
#define ATYN(n) cout << ( (n) ? "Yes":"No") << endl;
#define CFYN(n) cout << ( (n) ? "YES":"NO") << endl;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;

int main(void)
{
    IOS
    int n; cin >> n;
    map<int,int> m;
    REP(i,n) {
        int x;
        cin >> x;
        m[x]++;
    }

    priority_queue<int> pq;
    for(auto p:m) {
        // cerr << p.second << endl;
        pq.push(p.second);
    }
    // cerr << endl;
    while(pq.top() != 1) {
        int t = pq.top(); pq.pop();
        // cerr << t << endl;
        if (t > 2) {
             t = t % 2 == 0 ? 2 : 1;
            pq.push(t);
        } else { 
            int s = pq.top(); pq.pop();
            if (s == 2) { // 2 2 -> 1 1
                REP(i,2) pq.push(1);
            } else pq.push(1); // 2 1 -> 0 1
        }
    }

    cout << pq.size() << endl;

    return 0;
}