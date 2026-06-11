#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int solve(){
    string s;
    cin >> s;
    int l = s.size();
    for(int i = 0; i < l - 1; i++){
        if(s[i] == s[i + 1]){
            return cout << i + 1 << " " << i + 2 << "\n", 0;
        }
    }
    for(int i = 0; i < l - 2; i++){
        if(s[i] == s[i + 2]){
            return cout << i + 1 << " " << i + 3 << "\n", 0;
        }
    }
    cout << -1 << " " << -1 << "\n";
 }

int main() {
#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

