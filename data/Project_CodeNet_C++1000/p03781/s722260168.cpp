#include<bits/stdc++.h>
using namespace std;
#define Q int tc; scanf("%d",&tc);cin.ignore(); for(int q=1;q<=tc;q++)
typedef long long int ll;
#define MAX 100000

int main()
{
    ll x;
    cin>>x;
    double ans=(-1+sqrt(1+8*x))/2;
    cout<<ceil(ans);
}

