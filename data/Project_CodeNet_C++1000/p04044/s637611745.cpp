#include <bits/stdc++.h>
using namespace std;


void solve(){
    int n, l;
    cin >> n >> l;
    vector<string> vs;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        vs.push_back(s);
    }
    sort(vs.begin(), vs.end());
    for(string s : vs)
        cout << s;
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




