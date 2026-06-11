#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{

    ll a,b,x,res=0;
    cin >> a >> b >> x;

    if(a%x==0)
        res =(b/x) - (a/x) +1;
    else
        res = (b/x) - (a/x);
              cout << res << endl;
    return 0;
}