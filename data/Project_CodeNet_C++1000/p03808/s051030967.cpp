#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200100;

using namespace std;

long long n;
long long a[N], b[N], A[N], B[N];

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        cin >> n;
        long long S = 0;
        for(int i = 0; i < n; i++){
                cin >> a[i];
                S += a[i];
        }
        if(S % (n * (n + 1) / 2)){
                cout << "NO" << "\n";
                return 0;
        }
        long long k = S / (n * (n + 1) / 2);
        for(int i = 0; i < n; i++){
                a[i] -= k;
                if(a[i] < 0){
                        cout << "NO" << "\n";
                        return 0;
                }
        }
        for(int i = 0; i < n; i++){
                b[i] = a[i] - a[(i - 1 + n) % n];
                b[i] = k - b[i];
                if(b[i] < 0 || b[i] % n){
                        cout << "NO" << "\n";
                        return 0;
                }
                b[i] /= n;

                A[i] += b[i];
                A[i + n] -= b[i];
                B[i] += - b[i] * i;
                B[i + n] -= - b[i] * i;

        }
        for(int i = 1; i < 2 * n; i++){
                A[i] += A[i - 1];
                B[i] += B[i - 1];
        }
        for(int i = 0; i < n; i++){
                if(a[i] != B[i] + B[i + n] + A[i] * i + A[i + n] * (n + i)){
                        cout << "NO" << "\n";
                        return 0;
                }
        }
        cout << "YES" << "\n";
}
