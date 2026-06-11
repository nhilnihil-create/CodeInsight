#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int len = 5005;
int arr[len];
bool pref[len][len], suf[len][len];

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &arr[i]);

    pref[0][0] = suf[n+1][0] = true;
    for (int i = 1; i <= n; i++)
        for (int j = k; j >= 0; j--)
            if (pref[i-1][j] == true)
                pref[i][j] = pref[i][min(k, j+arr[i])] = true;

    for (int i = n; i >= 1; i--)
        for (int j = k; j >= 0; j--)
            if (suf[i+1][j] == true)
                suf[i][j] = suf[i][min(k, j+arr[i])] = true;

    //for (int j = 0; j <= k; j++)
      //  printf("sum = %d, pref = %d, suf = %d\n", j, pref[n][j], suf[1][j]);

    int ans = 0;
    for (int i = 1; i <= n; i++){
        int un = 1;
        for (int a = k-1, b = 0, mx = 0; a >= 0; a--){
            if (pref[i-1][a] == false)
                continue;

            while (b < k-1-a){
                b++;
                if (suf[i+1][b])
                    mx = b;
            }

            //printf("a = %d, mx = %d\n", a, mx);

            if (mx+a+arr[i] >= k)
                un = 0;
        }

        ans += un;
        //printf("i = %d, up = %d, un = %d\n", i, up, un);
    }

    printf("%d\n", ans);
    return 0;
}
