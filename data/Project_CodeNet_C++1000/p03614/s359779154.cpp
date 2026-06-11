#include<bits/stdc++.h>
using namespace std;
int arr[100005];
int main()
{
int n, ans=0;
cin>>n;
for(int a=1; a<=n; a++)
cin>>arr[a];
for(int a=1; a<=n; a++)
{
if(arr[a]==a)
{
ans++;
swap(arr[a], arr[a+1]);
}
}
cout<<ans;
return 0;
}