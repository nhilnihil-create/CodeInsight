#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const long long INF = 1e15;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int n,k;
    cin >> n >> k;
    int g;
    cin >> g;
    int mx = g;
    if(k == g){
        cout << "POSSIBLE" << endl;
        return 0;
    }
    for(int i = 0; i < n-1; i++){
        int a; cin >> a;
        mx = max(mx,a);
        g = __gcd(g,a);
        if(k == a){
            cout << "POSSIBLE" << endl;
            return 0;
        }
    }
    if(g == 1 && mx > k) cout << "POSSIBLE" << endl;
    else if(k%g == 0 && mx > k) cout << "POSSIBLE" << endl;
    else cout << "IMPOSSIBLE" << endl;
    return 0;
}