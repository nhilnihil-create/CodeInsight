#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll ara[100005];
int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++)scanf("%d", &ara[i]);
    ll res= 0;
    for(int i=n-1; i>0; i--)
    {
        int p1= ara[i];
        int p2= ara[i-1];
        int x= min(ara[i-1], ara[i]);;
        res+= x;
        ara[i-1]-= x;
        ara[i]-= x;
        res+= (ara[i]/2);
        ara[i]-= ((ara[i]/2)*2);
        if(ara[i]==1 && ara[i]!=p1 && ara[i-1]!=p2)ara[i-1]++;
    }
    res+= (ara[0]/2);
    printf("%lld\n", res);
    return 0;
}
