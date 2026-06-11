#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int main() {
#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, l;
    cin >> n >> l;
    vector <string> s(n);
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    sort(s.begin(), s.end());
    string ans = "";
    for(int i = 0; i < n; i++){
        ans += s[i];
    }
    cout << ans << "\n";
    return 0;
}