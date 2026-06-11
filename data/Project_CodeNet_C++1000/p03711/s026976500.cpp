#include<bits/stdc++.h>
using namespace std;
#define ll long long
int prime(int n)
{
    ll i;
    if(n==1){return 0;}
    else if(n==2){return 1;}
    else
    {
        for(i=2;i<n;i++)
        {
            if(n%i==0){return 0;}
        }
    }
    return 1;
}
int main()
{

    ll n,i,j,k,l,a,b,c,d,m,f1,f2;
    cin>>a>>b;
    ll arr[10]={1,3,5,7,8,10,12};
    ll arr1[10]={4,6,9,11};
    ll arr2[10]={2};
    f1=-1;
    f2=-1;
    for(i=0;i<6;i++)
    {
        if(arr[i]==a){f1=1;}
        if(arr[i]==b){f2=1;}
    }
    if(f1==1&&f2==1)
    {
        cout<<"Yes"<<endl;
        return 0;
    }
    f1=-1;
    f2=-1;
    for(i=0;i<5;i++)
    {

        if(arr1[i]==a){f1=1;}
        if(arr1[i]==b){f2=1;}
    }
    if(f1==1&&f2==1)
    {
        cout<<"Yes"<<endl;
        return 0;
    }
    f1=-1;
    f2=-1;
    for(i=0;i<1;i++)
    {
        if(arr2[i]==a){f1=1;}
        if(arr2[i]==b){f2=1;}
    }
    if(f1==1&&f2==1)
    {
        cout<<"Yes"<<endl;
        return 0;
    }
    cout<<"No"<<endl;
    return 0;
}
