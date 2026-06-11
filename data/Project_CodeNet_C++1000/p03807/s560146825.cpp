#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int sum=0;
    while(n--)
    {
        int x;
        cin>>x;
        sum+=(x%2);
    }
    if(sum%2==1)cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    return 0;
}