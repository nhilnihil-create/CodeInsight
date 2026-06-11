#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); ++i)
#define rep2(i,n) for(int i=1; i<=(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define all(x) (x).begin(),(x).end()
#define Sort(x) sort((x).begin(),(x).end())
#define Sort2(x) sort((x).begin(),(x).end(), greater<int>())
const int INF = 1001001001;

int main()
{
    int n; cin >> n;
    vector<int> a(3*n); rep(i, 3*n) cin >> a[i];
    Sort2(a);
    ll ans = 0;
    rep(i,2*n){
        if(i%2==1) ans += a[i];
    }
    cout << ans << endl;
}

/*
Ctrl+@
g++ a.cpp
./a.out
*/