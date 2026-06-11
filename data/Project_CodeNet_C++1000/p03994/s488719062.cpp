#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define endl '\n'
#define ll long long
#define P pair<int,int>

signed main() {
    string s;
    int k;
    cin >> s >> k;

    int n = s.size();
    vector<int> a(n);

    for(int i = 0; i < n; i++){
        int x = s[i] - 'a';
        a[i] = x;
    }

    for(int i = 0; i < n; i++){
        if(i == n - 1){
            a[i] += k;
            a[i] %= 26;
            break;
        }

        if(a[i] == 0) continue;
        if(a[i] + k < 26) continue;

        k -= (26 - a[i]);
        a[i] += (26 - a[i]);
        a[i] %= 26;
    }

    for(int i = 0; i < n; i++){
        char c = a[i] + 'a';
        cout << c;
    }
    cout << endl;
}

