#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize(4)
#include<bits/stdc++.h>
using namespace std;
#define y1 y11
#define fi first
#define se second
#define pi acos(-1.0)
#define LL long long
#define ll long long
//#define mp make_pair
#define pb push_back
#define ls rt<<1, l, m
#define rs rt<<1|1, m+1, r
#define ULL unsigned LL
#define pll pair<LL, LL>
#define pli pair<LL, int>
#define pii pair<int, int>
#define piii pair<pii, int>
#define pdd pair<double, double>
#define mem(a, b) memset(a, b, sizeof(a))
#define debug(x) cerr << #x << " = " << x << "\n";
#define fio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//head

const int N = 1e5 + 10;
int n, a[N];
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    sort(a+1, a+1+n, greater<int>());
    int s;
    for (int i = 1; i <= n; ++i) {
        if(i+1 > a[i+1]) {
            if((a[i]-i)%2) {
                s = 1;
                break;
            }
            s = 0;
            for (int j = i+1; j <= n; ++j) {
                if(a[j] == i) s ^= 1;
                else break;
            }
            break;
        }
    }
    if(s) puts("First");
    else puts("Second");
    return 0;
}
