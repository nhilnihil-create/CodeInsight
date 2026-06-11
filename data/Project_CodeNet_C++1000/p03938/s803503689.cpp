#include <bits/stdc++.h>
using namespace std;
#define fi first
#define endl "\n"
#define se second
#define ll long long
//priority_queue<int, vector<int>, greater<int> > pq;
#define _CRT_SECURE_NO_DEPRECATE
const int N = 105;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
const ll mod =  1e9+7;
const int M=25000;
int A[M];
int B[M];
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 int n;
    cin >> n;
    for(int i = 1; i <= n ; i ++ ){
        A[i] = M * i;
        B[i] = M * (n - i + 1);
    }
    int p;
    for(int i = 1; i <= n; i ++ ){
        cin >> p;
        A[p] += i;
    }
    for(int i = 1; i <= n ; i ++ )
        cout << A[i] << " ";
    cout << "\n";
    for(int i = 1; i <= n ; i ++ )
        cout << B[i] << " ";

}