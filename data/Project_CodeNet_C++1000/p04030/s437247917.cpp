#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

void solve(){
    string s;
    cin >> s;
    string ans = "";
    for(char i:s) {
        if(i != 'B')
            ans += i;
        else if(ans.size())
            ans.pop_back();
    }
    cout <<  ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t =1;
    while(t--)
        solve();
    return 0;
}

