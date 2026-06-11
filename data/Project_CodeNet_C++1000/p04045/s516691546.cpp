#include <bits/stdc++.h>
using namespace std;


void solve(){
    vector<int> digits;
    int n, k;
    cin >> n >> k;
    for(int i = 0, q; i < k; i++){
        cin >> q;
        digits.push_back(q);
    }
    for(int i = n;1;i++){
        bool good = true;
        for(int p : digits){
            if(!good) break;
            int t = i;
            while(t > 0){
                if(t%10 == p){
                    good = false;
                    break;
                }
                t/=10;
            }
        }
        if(good){
            cout << i << "\n";
            return;
        }
    }
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




