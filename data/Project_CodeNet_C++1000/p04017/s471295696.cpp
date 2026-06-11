#include <algorithm>
#include <iostream>
using namespace std;

int d[100002][20];

int power2(int n){
    int res = 1;
    for(int i = 0; i < n; i++) res *= 2;
    return res;
}

int main()
{
    int n;
    cin >> n;
    int x[100002];
    for(int i = 0; i < n; i++) cin >> x[i];
    int l;
    cin >> l;
    for(int i = 0; i < n; i++){
        d[i][0] = (upper_bound(x, x + n, x[i] + l) - x) - 1;
    }
    for(int j = 1; j < 20; j++){
        for(int i = 0; i < n; i++){
            d[i][j] = d[d[i][j - 1]][j - 1];
        }
    }
    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if(a > b) swap(a, b);
        int ans = 0;
        while(d[a][0] < b){
            for(int j = 0; j < 20; j++){
                if(d[a][j] >= b){
                    a = d[a][j - 1];
                    ans += power2(j - 1);
                    break;
                }
            }
        }
        ans++;
        cout << ans << endl;
    }
}