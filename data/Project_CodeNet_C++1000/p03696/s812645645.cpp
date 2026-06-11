#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    string s;
    cin >> n >> s;
    int l=0;
    int r=0;

    for(int i = 0; i < n; i++) {
        if(s[i]=='(') l++;
        else{
            if(l!=0) l--;
            else r++;
        }
    }

    cout << string(r,'(')+s+string(l,')') << "\n";

    return 0;
}