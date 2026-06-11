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

const int maxn = 1000* 100 + 5;
pll a[maxn];

int32_t main(){
    int n, ans = 0;
    cin >>n;
    for(int i = 0; i < n; i ++){
        cin >>a[i].F;
        a[i].S = i;
    }
    sort(a, a + n);
    for(int i = 0; i < n; i ++){
        if(a[i].S % 2 != i % 2)
            ans ++;
    }
    cout <<ans/ 2 <<endl;
    return false;
}
