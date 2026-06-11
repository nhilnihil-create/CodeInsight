#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
    fastIO;
    int n, m, h, w;
    cin >> n >> m >> h >> w;
    if(n % h == 0 && m % w == 0){
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n";
    for(int i = 0 ; i < n; i ++ ){
        for(int j = 0 ; j < m ; j ++ ){
            if(i % h == 0 && j % w == 0){
                cout << 500 * (h * w - 1) - 1  << " ";
            }
            else{
                cout << -500 << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}