#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,a[100000],i,cnt=1;
    cin >> n;
    for(i=0;i<n;i++)cin >> a[i];
    sort(a,a+n);
    for(i=1;i<n;i++) if(a[i-1]!=a[i])cnt++;
    cout << cnt - (n-cnt)%2;
    return 0;
}