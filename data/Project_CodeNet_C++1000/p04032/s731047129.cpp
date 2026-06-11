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
    int r=0;
    for(int i = 0; i < n-2; i++) {
        if(s[i]==s[i+1] || s[i+1]==s[i+2] || s[i+2]==s[i]){
            cout << i+1 << " " << i+3 << "\n";
            return 0;
        }
    }
    if(n==2 && s[0]==s[1]) cout << "1 2" << "\n";
    else cout << "-1 -1" << "\n";
    return 0;
}