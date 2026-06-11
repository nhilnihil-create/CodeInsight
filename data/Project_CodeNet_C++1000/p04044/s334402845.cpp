#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

int n, l;
vector<string>s;
void solve(){
    cin >> n >> l;
    for(int i=0;i<n;++i) {
        string t;
        cin >> t;
        s.push_back(t);
    }
    sort(s.begin(), s.end());
    for(string i:s)
        cout << i ;
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t =1;
    while(t--)
        solve();
    return 0;
}

