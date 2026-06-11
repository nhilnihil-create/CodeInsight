#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll ara[300005];
int main()
{
    int n;
    scanf("%d", &n);
    for(int i=1; i<=3*n; i++)scanf("%d", &ara[i]);
    sort(ara+1, ara+1+3*n);
    ll res= 0;
    for(int i=3*n -1, j=0; j<n; i-= 2, j++)res+= ara[i];
    printf("%lld\n", res);
    return 0;
}
