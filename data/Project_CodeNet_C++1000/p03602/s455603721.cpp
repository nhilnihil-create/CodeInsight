#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> PA;
typedef priority_queue<int> PQ;
typedef vector<int> VE;
#define int long long
#define INF 1000000009
#define INFL 1000000000000000018
#define mod 1000000007
#define pb push_back
#define MAXN 400

int n, a[MAXN][MAXN], b[MAXN][MAXN], res, ans;

signed main()
{
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
            b[i][j] = a[i][j];
            if(i < j)ans += a[i][j];
        }
    }
    //printf("ans %lld\n", ans);
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                b[i][j] = min(b[i][j], b[i][k] + b[k][j]);
                //printf("%lld %lld %lld\n", i, j, b[i][j]);
            }
        }
    }
    //printf("\n\n");
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            for(int k = 0; k < n; k++){
                if(i == k || j == k) continue;
                if(a[i][j] > b[i][k] + b[k][j]){
                    printf("-1\n");
                    return 0;
                }
                if(a[i][j] == b[i][k] + b[k][j]){
                    ans -= a[i][j];
                    break;
                    //printf("%lld %lld %lld\n", i, j, a[i][j]);
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}
