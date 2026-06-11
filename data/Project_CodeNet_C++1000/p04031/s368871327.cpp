#include <bits/stdc++.h>
using namespace std;


void solve(){
    int n; cin >> n;
    vector<int> A;
    for(int i = 0; i < n; i++){
        int k; cin >> k;
        A.push_back(k);
    }
    int best_ans = 1e9;
    for(int i = -100; i <= 100; i++){
        int curr = 0;
        for(int j : A){
            curr += (j-i)*(j-i);
        }
        best_ans = min(curr, best_ans);
    }
    cout << best_ans << "\n";
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




