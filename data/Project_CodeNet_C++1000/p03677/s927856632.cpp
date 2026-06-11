#include<bits/stdc++.h>

using namespace std;

#define ll  long long
#define ld  double

#define sz(x)   (int)x.size()
#define all(x)  x.begin(),x.end()

#define pb  emplace_back
#define X   first
#define Y   second

const int   N   = 2e5 + 5;

ll  a[N];
ll  b[N];

void upd(int l,int r,int s,int c)   {   ++r;
    a[l] += s;  b[l] += c;
    a[r] -= s;  b[r] -= c;
}

int main()  {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;  cin >> n;
    int m;  cin >> m;
    int l = 0;

    for(int i = 0 ; i < n ; ++i)    {
        int x;  cin >> x;

        if (l)  {
            if (l <= x) {
                upd(l + 1,x,-1,x + 1);
                upd(x + 1,m, 0,x - l);
                upd(1,l,0,x - l);
            }
            else   {
                upd(l + 1,m,-1,x + m + 1);
                upd(x + 1,l, 0,x + m - l);
                upd(1,x,-1,x + 1);
            }   
        }
        l = x;
    }
    for(int i = 1 ; i <= m ; ++i)
        a[i] += a[i - 1],
        b[i] += b[i - 1];
    
    ll  ans = 1e18;

    for(int i = 1 ; i <= m ; ++i)
        if (ans > a[i] * i + b[i])
            ans = a[i] * i + b[i];

    cout << ans << endl;
}