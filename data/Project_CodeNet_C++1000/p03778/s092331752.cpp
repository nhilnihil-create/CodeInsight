#include<bits/stdc++.h>
#define speed_up ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
#define ara(A,N) sort(A,A+N)
#define rev(A,N) sort(A,A+N,greater<long long>())
using namespace std;
int main()
{   speed_up;
    ll a, b, w, n, m;
    cin>>w;
    cin>>n>>m;
    b = max(m, n);
    a = min(m, n);
    if(b>a+w)
    {
        cout<<b-a-w<<endl;
        return 0;
    }
    else
    {
        cout<<0<<endl;
        return 0;
    }

    return 0;

}





