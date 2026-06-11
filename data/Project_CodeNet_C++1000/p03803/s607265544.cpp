#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define INF 1e9
#define st string
#define pb push_back
#define eb emplace_back
#define pii pair<int, int>
#define fopen freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define test(x) int t; cin >> t; while(t--) x();

//int dx[] = {0, 0, 1, -1};
//int dy[] = {1, -1, 0, 0};

void solve(){
    int a, b; cin >> a >> b;
    if(a == b) {
        cout << "Draw";
        return;
    }
    if(a == 1) {
        cout << "Alice";
        return;
    }
    if(b == 1) {
        cout << "Bob";
        return;
    }
    if(a < b) {
        cout << "Bob";
        return;
    }
    if(a > b) cout << "Alice";
}

int main(){
    fastio
    solve();
    return 0;
}

