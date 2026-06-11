#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 2e9;
//const ll INF = 9e18;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    vector<int> pos(26,-1);
    vector<int> len(26);
    int N = s.size();
    for (int i=0;i<N;i++){
        int p = s[i]-'a';
        len[p] = max(len[p], i-pos[p]-1);
        pos[p] = i;
    }
    for (int i=0;i<26;i++){
        len[i] = max(len[i],N-1-pos[i]);
    }
    int ans = INF;
    for (int i=0;i<26;i++){
        ans = min(ans, len[i]);
    }
    cout << ans << "\n";
}