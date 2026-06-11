#include<bits/stdc++.h>
#define speed_up ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
#define ara(A,N) sort(A,A+N)
#define rev(A,N) sort(A,A+N,greater<long long>())
using namespace std;
int main()
{   speed_up;
    ll n, m, ans = 0;
    cin>>n>>m;
    if(m>n)
    {
        m = m - n*2;
        ans += n + m/4;
    }
    else
    {
        ans += m/2;
    }
 cout<<ans<<endl;

    return 0;

}





