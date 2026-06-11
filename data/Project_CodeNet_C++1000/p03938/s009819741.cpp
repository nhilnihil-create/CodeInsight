#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;

using namespace std;

int n;
int A[N];
int B[N];

int main()
{
        ios_base::sync_with_stdio(false);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        cin >> n;
        for(int i = 1; i <= n; i++){
                int x;
                cin >> x;
                A[x] += i;
                B[x] += i;
        }
        for(int i = 1; i <= n; i++){
                A[i] += A[i - 1];
        }
        for(int i = n; i >= 1; i--){
                B[i] += B[i + 1];
        }
        for(int i = 1; i <= n; i++){
                A[i] += i;
                B[n - i + 1] += i;
        }
        for(int i = 1; i <= n; i++){
                cout << A[i] << " \n"[i == n];
        }
        for(int i = 1; i <= n; i++){
                cout << B[i] << " \n"[i == n];
        }
}
