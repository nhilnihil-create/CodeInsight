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

const int maxn = 105;
int cn[maxn];

int32_t main(){
    int n, mx = 0;
    cin >>n;
    for(int i = 0; i < n; i ++){
        int x;
        cin >>x;
        xmax(mx, x);
        cn[x] ++;
    }
    bool ans = true;
    if(mx == 1){
        if(n > 2)
            ans = false;
    }
    else if(mx % 2){
        if(cn[(mx + 1)/ 2] != 2)
            ans = false;
        for(int i = 0; i < (mx + 1)/ 2; i ++){
            if(cn[i] > 0)
                ans = false;
        }
        for(int i = (mx + 1)/ 2 + 1; i <= mx; i ++){
            if(cn[i] < 2)
                ans = false;
        }
    }
    else{
        if(cn[mx/ 2] != 1)
            ans = false;
        for(int i = 0; i < mx/ 2; i ++){
            if(cn[i] > 1)
                ans = false;
        }
        for(int i = mx/ 2 + 1; i <= mx; i ++){
            if(cn[i] < 2)
                ans = false;
        }
    }
    if(!ans)
        cout <<"Impossible" <<endl;
    else
        cout <<"Possible" <<endl;
    return false;
}
