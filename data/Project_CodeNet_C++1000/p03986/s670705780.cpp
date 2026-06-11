#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    int n=s.size();

    int ans=0;
    int scnt=0;
    for(int i = 0; i < n; i++) {
        if(s[i]=='T' && scnt==0) continue;
        if(s[i]=='S') scnt++;
        else{
            scnt--;
            ans++;
        }
    }
    cout << n-ans*2 << "\n";

    return 0;
}