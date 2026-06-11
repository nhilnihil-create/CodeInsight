#include<iostream>
#include<algorithm>
using namespace std;
int n,sum,s;
bool a[100010];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s;
        if(a[s])sum++;
        else a[s]=1;
    }
    if(sum%2==1)sum++;
    cout<<n-sum;
}