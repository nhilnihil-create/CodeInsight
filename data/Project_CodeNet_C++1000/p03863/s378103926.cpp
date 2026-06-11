#include "bits/stdc++.h"
using namespace std;
 
using ll = long long;
 
const ll inf = 1e18;
const int N = 2 * 1e5 + 10;

ll res;
ll a[N];

void solve(){
    string s;
    cin >> s;
    std::vector<char> v;
    for (int i = 0; i < s.size() - 1; ++i){
        if(!v.size()){
            v.push_back(s[i]);
            continue;
        }else{
            v.push_back(s[i]);
            while(v.size() >= 2 && s[i + 1] != v[v.size() - 2]){
                v.pop_back();
                res++;
            }
        }
    }
    if(res & 1) cout << "First\n";
    else cout << "Second\n";
}
 
int main(int argc, char const *argv[]){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    ll t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
// Radhe Radhe