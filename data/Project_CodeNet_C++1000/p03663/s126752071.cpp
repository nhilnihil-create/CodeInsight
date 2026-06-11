#include<bits/stdc++.h>

using namespace std;

#define ll  long long
#define ld  double

#define sz(x)   (int)x.size()
#define all(x)  x.begin(),x.end()

#define pb  emplace_back
#define X   first
#define Y   second

bool ask(ll  x) {
    cout << "? " << x << "\n";
    char c; cin >> c;

    return  c == 'Y';
}

int main()  {
    ios_base::sync_with_stdio(0);
    //cin.tie(0); cout.tie(0);

    if (ask(1e10))   {
        int ans = 1;
        for(int i = 0 ; i < 11 ; ++i)
            if (ask(pow(10ll,i) + 1))   {
                ans = pow(10ll,i);
                break;
            }
        
        cout << "! " << ans;
        return  0;
    }

    ll  l, r;

    for(int i = 1 ; i <= 12 ; ++i)
        if(!ask(pow(10ll,i))) {
            r = pow(10ll,i) - 1;
            l = pow(10ll,i - 1);

            break;
        }
    while (l < r)   {
        ll  m = (l + r) / 2;

        if (ask(m * 10))    r = m;
        else                l = m + 1;   
    }
    cout << "! " << l << "\n";
}