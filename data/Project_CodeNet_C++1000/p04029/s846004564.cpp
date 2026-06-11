#include <bits/stdc++.h>
using namespace std;


void solve(){
    long long n; cin >> n;
    cout << n*(n+1)/2;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    bool multitest = false;
//    multitest = true;
    if(multitest){
        int t; cin >> t;
        while(t--)
            solve();
    }
    else
        solve();
}




