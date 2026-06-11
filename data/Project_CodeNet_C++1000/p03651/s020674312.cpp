#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef pair<int, int> pi;

int n;
const int maxn = 1e5 + 5;
int a[maxn], k;

int gcd(int x, int y){
    return y == 0 ? x : gcd(y, x % y);
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    int g = 0;
    int mx = 0;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        g = gcd(g, a[i]);
        mx = max(mx, a[i]);
    }
    if(mx < k){
        cout << "IMPOSSIBLE" << endl;
    }else{
        if((mx - k) % g == 0){
            cout << "POSSIBLE" << endl;
        }else{
            cout << "IMPOSSIBLE" << endl;
        }
    }
    return 0;
}
