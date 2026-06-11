#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
constexpr ll MOD = ll(1e9+7);


int main(){
    string s, t;
    int n, m;
    cin >> s >> t;
    n = s.size();
    m = t.size();
    vector<int> scnt(n+1), tcnt(m+1);
    for(int i=0;i<n;i++){
        scnt[i+1] = scnt[i] + (s[i] == 'A' ? 1 : 2);
    }
    for(int i=0;i<m;i++){
        tcnt[i+1] = tcnt[i] + (t[i] == 'A' ? 1 : 2);
    }
    int q;
    cin >> q;
    for(int i=0;i<q;i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--; c--;
        cout << ((scnt[b]-scnt[a])%3 == (tcnt[d]-tcnt[c])%3 ? "YES" : "NO") << endl;
    }
    return 0;
}