#include<bits/stdc++.h>
using namespace std;
int ara[100005], b[100005];
map<int, int>mp;
int main()
{
    int n, x, res= 0, cnt= 0;
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
    scanf("%d", &ara[i]), b[i]= ara[i];
    sort(b+1, b+1+n);
    for(int i=1; i<=n; i++)mp[ b[i] ]= ++cnt;
    for(int i=1; i<=n; i++)ara[i]= mp[ ara[i] ];
    for(int i=1; i<=n; i++)res+= abs(i-ara[i])%2;
    printf("%d\n", res/2);
    return 0;
}
