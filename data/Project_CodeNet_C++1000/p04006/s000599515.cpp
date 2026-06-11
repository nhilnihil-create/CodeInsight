///not today

#include<bits/stdc++.h>
using namespace std;

#define SZ(x) (int)(x).size()
#define pb push_back
#define ll long long
#define xmax(x, y) (x) = max((x), (y))
#define xmin(x, y) (x) = min((x), (y))
#define F first
#define S second
#define pii pair<int, int>
#define pll pair<long long, long long>
#define int long long
#define pipii pair< int, pair<int, int> >
#define plpll pair< ll, pair<ll, ll> >

const int maxn = 2005;
int ans[maxn], a[maxn];

int32_t main(){
    int n, x, sum = 0;
    cin >>n >>x;
    for(int i = 0; i < n; i ++)
        cin >>a[i];
    for(int i = 0; i < n; i ++){
        ans[i] = a[i];
        sum += a[i];
    }
    for(int i = 1; i < n; i ++){
        int s = i* x;
        for(int j = 0; j < n; j ++){
            xmin(ans[j], a[(j + n - i)% n]);
            s += ans[j];
        }
        xmin(sum, s);
    }
    cout <<sum <<endl;
    return false;
}
