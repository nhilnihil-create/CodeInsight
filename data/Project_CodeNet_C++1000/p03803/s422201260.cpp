#include <bits/stdc++.h>
using namespace std;
#define fo(x, n) for(int i = x; i <= n; i++)
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector <int> vi;
const int MOD = 1e9 + 7;

void solve(){
    int a, b;
    cin >> a >> b;
    int x = 0;
    if(a == b) x = 1;
    else if(a == 1 || b == 1){
        if(a == 1) x = 2;
        else x = 3;
    }
    else{
        if(a > b) x = 2;
        else x = 3;
    }
    cout << (x == 1 ? "Draw" : x == 2 ? "Alice" : "Bob");
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
	int T = 1;
    //cin >> T;
    fo(1, T){
        solve();
    }
}

