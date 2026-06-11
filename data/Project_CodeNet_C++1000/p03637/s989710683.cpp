#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll arr[200009];
int main()
{
    ll n,t,m,x,i,j,k,maxi = INT_MIN,mini = INT_MAX,flag =0,sum=0,sum1=0;
    vector<ll>vi;
    cin>>n;
    for(i = 0 ;i<n; i++)
    {
        cin>>x;
        if(x% 4==0)
            sum++;
        else if(x%4 == 2)
            sum1++;
    }
    n--;
    if(sum1>0){
            sum1--;
    n-=sum1;
    }
    n-=sum*2;
   // cout<<n<<endl;
    if(n<=0)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}
