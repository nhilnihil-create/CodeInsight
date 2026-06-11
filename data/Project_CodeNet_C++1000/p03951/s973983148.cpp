#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 1e9
#define ALL(v) v.begin(), v.end()

using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin >> n;
    string s, t;
    cin >> s >> t;

    if (n > s.size()+t.size()){
        cout << s.size()+t.size() << endl;
        return 0;
    }
    int mostOverlap = s.size() + t.size() - n;
    int minlen = s.size()+t.size();

    FOR(i, 1, mostOverlap+1){
        // cout << i << ": " << s.substr(s.size()-i, i) << " " << t.substr(0, i) << endl;
        if (s.substr(s.size()-i, i) == t.substr(0, i)){
            if (s.size()+t.size()-i < minlen) minlen = s.size()+t.size()-i;
        }
    }
    cout << minlen << endl;
}
