#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    int u[100005], v[100005];
    u[0] = v[0] = 0;
    for(int i = 1; i <= n; i++) u[i] = u[i - 1] + s[i - 1] - 'A' + 1;
    for(int i = 1; i <= m; i++) v[i] = v[i - 1] + t[i - 1] - 'A' + 1;
    int q;
    cin >> q;
    while(q--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if((u[b] - u[a - 1]) % 3 == (v[d] - v[c - 1]) % 3) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
