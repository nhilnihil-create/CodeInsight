#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    long long n=s.size();
    long long cnt[26];
    fill(cnt,cnt+26,0);
    long long ans = 1;
    for(int i=0; i<n; i++){
        ans += cnt[s[i]-'a'];
        for(int j=0; j<26; j++){
            if(s[i]-'a' != j){
                cnt[j]++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
