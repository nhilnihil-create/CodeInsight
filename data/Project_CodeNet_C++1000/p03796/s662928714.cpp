#include<bits/stdc++.h>
#define ull unsigned long long
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define mod 1000000007
using namespace std;
int main()
{
    fastio;
    ull n,fact=1,i;
    cin>>n;
    for (i=1;i<=n;i++)
        fact = (fact*i)%(mod);
    cout<<fact<<endl;
}