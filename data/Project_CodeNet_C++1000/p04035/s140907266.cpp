#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const int mod = 998244353;

using namespace std;

int n;
int a[N];

int main()
{
    ios_base::sync_with_stdio(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int m;
    cin >> n >> m;
    int res = -1;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(i > 1 && a[i] + a[i - 1] >= m){
            res = i - 1;
        }
    }
    if(res == -1){
        cout << "Impossible" << "\n";
        return 0;
    }
    cout << "Possible" << "\n";
    for(int i = 1; i < res; i++) cout << i << "\n";
    for(int i = n - 1; i >= res; i--) cout << i << "\n";
}

