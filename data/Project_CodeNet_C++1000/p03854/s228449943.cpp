#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define rep1(i, n) FOR(i, 1, n+1)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; --i)
#define whole(x) (x).begin(),(x).end()
#define rwhole(x) (x).rbegin(), (x).rend()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
#define P pair<int, int>
#define debug(var) cerr << "[" << #var << "] " << var << endl
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
const ll mod = 1000000007;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};


int main(){
    string s;
    cin >> s;
    int i = 0;
    bool ok = true;
    int n = s.size();
    reverse(whole(s));
    while (i<n) {
        //debug(i);
        string u = s.substr(i, 7);
        if (u=="remaerd") {
            i += 7;
            continue;
        }
        string x = s.substr(i, 6);
        if (x=="resare") {
            i += 6;
            continue;
        }
        string y = s.substr(i, 5);
        if (y=="maerd" || y=="esare") {
            i += 5;
            continue;
        }
        break;
    }
    
    if (i==n) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    
    
    return 0;
}
