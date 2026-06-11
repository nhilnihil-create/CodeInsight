#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    string s, t;
    int a[100005] = {}, b[100005] = {}, q, x, y, u, v;
    cin >> s >> t;
    for (int i = 1; i <= (int)s.length(); i++) a[i] = a[i - 1] + (s[i - 1] == 'A');
    for (int i = 1; i <= (int)t.length(); i++) b[i] = b[i - 1] + (t[i - 1] == 'A');
    cin >> q;
    while (q--) {
        cin >> x >> y >> u >> v;
        int c = a[y] - a[x - 1], d = y - x + 1 - c, e = b[v] - b[u - 1], f = v - u + 1 - e;
        c %= 3; d %= 3; e %= 3; f %= 3;
        if ((c + 3 - d) % 3 == (e + 3 - f) % 3) cout << "YES\n";
        else cout << "NO\n";
    }
    /*
     AB/BA->X->AB/BA
     AABB->AAAAB->AB->X
     A->BB->AAAA->A
     A->BB->BAA->BABB->AAABB->AAAAAB->AAB
     AB->BBB->BBAA->BAAAA->BA
     1,0->0,2->2,1->4,0->1,0
     1,0->0,2->2,1->1,3->3,2->5,1->2,1
     0,0 1,1 2,2
     0,1 2,0 1,2
     1,0 0,2 2,1
     */
}
