#include<bits/stdc++.h>
#define speed_up ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
#define ara(A,N) sort(A,A+N)
#define rev(A,N) sort(A,A+N,greater<long long>())
using namespace std;
int main()
{
    speed_up;
    ll n, k;
    cin>>n>>k;
    ll ans;
    ans = k*pow((k-1), (n-1) );
    cout<<ans<<endl;



  return 0;
}

