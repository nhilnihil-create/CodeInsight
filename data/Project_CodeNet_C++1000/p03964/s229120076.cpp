#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;
    ll m; ll pa; ll pb;
    for(int i=0;i<N;i++){
        int a,b; cin >> a >> b;
        if(i==0) m = a+b;
        else{
            ll k = (m+pa+pb-1)/(pa+pb);
            ll l = max((pa*k+a-1)/a,(pb*k+b-1)/b);
            m = l*(a+b);
        }
        pa = a; pb = b;
    }
    cout << m;

    return 0;
}
