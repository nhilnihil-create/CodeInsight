#include<bits/stdc++.h>
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;



int main() {

    int n; cin >> n;
    string s,t; cin >> s >> t;
    int ans = 0;

    rep(i,n){
        if(s.substr(n-1-i,i+1) == t.substr(0,i+1)) {
            ans = i+1;
        }
    }

    cout <<  n*2-ans;

    return 0;
}









