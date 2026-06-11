#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

int a[10];
void solve(){
    for(int i=0;i<3;++i) {
        int t;
        cin >> t;
        a[t]++;
    }
    cout << (a[5] == 2 && a[7] == 1 ? "YES" : "NO") << "\n";

}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t =1;
    while(t--)
        solve();
    return 0;
}

