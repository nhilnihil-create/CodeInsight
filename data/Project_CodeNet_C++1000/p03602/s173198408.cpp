#include <bits/stdc++.h>

#define fi first
#define se second
#define ll long long

const int N = 303;

using namespace std;

int n;
int a[N][N];
bool dead[N][N];

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        cin >> n;
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                        cin >> a[i][j];
                }
        }
        long long res = 0;
        for(int i = 1; i <= n; i++){
                if(a[i][i]){
                        res = -1;
                }
                for(int j = 1; j <= n; j++){
                        if(i == j){
                                continue;
                        }
                        for(int h = 1; h <= n; h++){
                                if(h == j || h == i){
                                        continue;
                                }
                                if(a[i][j] + a[j][h] < a[i][h]){
                                        res = -1;
                                } else if(a[i][j] + a[j][h] == a[i][h]){
                                        dead[i][h] = dead[h][i] = 1;
                                }
                        }
                }
        }
        if(res == -1){
                cout << res << "\n";
                return 0;
        }
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                        if(!dead[i][j]){
                                res += a[i][j];
                        }
                }
        }
        cout << res / 2 << "\n";

}
