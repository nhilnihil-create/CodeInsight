#include <bits/stdc++.h>

using namespace std;

using ll = long long;
constexpr ll MOD = 1e9 + 7;
constexpr ll INF = 1e18;

int main() {
    ll n, m, i, j, k;
    string s;
    cin >> s;
    cin >> k;
    n = s.size();
    for(i=0;i<n;i++){
        if(s[i]!='a'&&'z'-s[i]+1<=k){
            k -= 'z' - s[i] + 1;
            s[i] = 'a';
            //cout << 'z'-s[i]+1 << endl;
        }
        if(k==0)break;
    }
    k%=26;
    if(k>0){
        s[n-1]='a'+((s[i-1]-'a'+k)%26);
    }
    cout << s << endl;
    return 0;
}