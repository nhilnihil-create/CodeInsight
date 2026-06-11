#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const int mod = 1e9 + 7;

using namespace std;

int n, k;
int a[N];
long long s[N];
long long A[N], B[N];

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        cin >> n >> k;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                s[i] = s[i - 1] + a[i];
                A[i] = A[i - 1] + max(a[i], 0);
        }
        for(int i = n; i >= 1; i--){
                B[i] = B[i + 1] + max(a[i], 0);
        }
        long long res = 0;
        for(int i = 1; i + k - 1 <= n; i++){
                res = max(res, A[i - 1] + B[i + k] + max(0ll, s[i + k - 1] - s[i - 1]));
        }
        cout << res << "\n";
}
