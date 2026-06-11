#include <bits/stdc++.h>
using namespace std;


void solve(){
    int a = 0, b = 0;
    for(int i = 0; i < 3; i++){
        int k; cin >> k;
        if(k == 5) a++;
        else if(k == 7) b++;
    }
    if(a == 2 && b == 1){
        cout << "YES\n";
    }
    else cout << "NO\n";
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




