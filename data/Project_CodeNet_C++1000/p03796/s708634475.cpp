#include<bits/stdc++.h>
#define speed_up ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
#define ara(A,N) sort(A,A+N)
#define rev(A,N) sort(A,A+N,greater<long long>())
using namespace std;
int main()
{   speed_up;
    ll mod = 1e9 + 7;
    //cout<<mod<<endl;
    ll power = 1;
    ll n;
    cin>>n;
    for(int i = 1; i<=n; i++)
    {
        power = (power*i)%mod;
    }
    cout<<power<<endl;

    return 0;

}





