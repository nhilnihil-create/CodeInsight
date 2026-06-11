#include <bits/stdc++.h>
using namespace std;
int ct[26];
int main(){
    string s;
    cin >> s;
    long long ans = 1;
    for (int i = 0; i < s.size(); i++){
        ans += i-ct[s[i]-'a'];
        ct[s[i]-'a']++;
    }
    printf("%lld",ans);
}
