#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9+7;

int main(){
    int n;
    cin >> n;
    vector<int> s(n);
    int ans = 0;
    int tmp = mod;
    for(int i = 0; i < n; i++){
        cin >> s[i];
        ans += s[i];
        if(tmp > s[i] && s[i]%10 != 0) tmp = s[i]; 
    }
    if(ans%10 != 0) cout << ans << endl;
    else if(tmp != mod) cout << ans-tmp << endl;
    else cout << 0 << endl;
    return 0; 
}