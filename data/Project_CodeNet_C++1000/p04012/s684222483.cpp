#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

string s;
int f[26];
void solve(){
    cin >> s;
    for(char i:s)
        f[i-'a']++;
    bool fl = 1;
    for(int i=0;i<26;++i)
        if(f[i]&1)
            fl = 0;
    cout << (fl ? "Yes":"No") << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t =1;
    while(t--)
        solve();
    return 0;
}

