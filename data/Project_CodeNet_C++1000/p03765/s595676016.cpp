#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const int BIG = 2e9 + 55;
const int maxN = 1e5 + 55;

char s[maxN], t[maxN];
int psums[maxN], psumt[maxN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> (s + 1);
    cin >> (t + 1);

    int n = strlen(s + 1);
    int m = strlen(t + 1);

    for(int i = 1; i <= n; i++){
        //cerr << ((s[i] == 'B') ? 1 : 2) << ' ';
        psums[i] = psums[i - 1] + ((s[i] == 'B') ? 1 : 2);
    }
    //cerr << '\n';

    for(int i = 1; i <= m; i++){
        //cerr << ((t[i] == 'B') ? 1 : 2) << ' ';
        psumt[i] = psumt[i - 1] + ((t[i] == 'B') ? 1 : 2);
    }
    //cerr << '\n';

    int q;  cin >> q;
    while(q--){
        int a, b, x, y; cin >> a >> b >> x >> y;
        int s1 = psums[b] - psums[a - 1];
        int s2 = psumt[y] - psumt[x - 1];
        //cerr << s1 << ' ' << s2 << '\n';
        if((s1 - s2) % 3 == 0){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}