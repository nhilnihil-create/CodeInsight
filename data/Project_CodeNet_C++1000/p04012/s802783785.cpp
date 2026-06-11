#include <bits/stdc++.h>
using namespace std;

char A[200];

void solve(){
    string s; cin >> s;
    for(char c : s)
        A[c]++;
    for(int i = 0; i < 200; i++){
        if(A[i]%2 != 0){
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    bool multitest = false;
    //multitest = true;
    if(multitest){
        int t; cin >> t;
        while(t--)
            solve();
    }
    else
        solve();
}




