#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
typedef pair<int,int> P;

int main(){
    string s;
    ll k;
    cin >> s >> k;
    int n = s.size();
    int a[n], b[n];
    rep(i, n){
        a[i] = ('z' - s[i] + 1) % 26;
    }

    rep(i, n - 1){
        if (k >= a[i]){
            cout << 'a';
            k -= a[i];
        }
        else cout << s[i];
    }
    cout << char('a' + ((s[n - 1] - 'a') + k) % 26) << endl;
    return 0;
}