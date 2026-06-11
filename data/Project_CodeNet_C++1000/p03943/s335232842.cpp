#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int a[3];
    cin>>a[0]>>a[1]>>a[2];
    sort(a,a+3);
    if(a[0]+a[1]==a[2])
    {
        cout<<"Yes";
    }
    else
    {
        cout<<"No";
    }
  	return 0;
}





