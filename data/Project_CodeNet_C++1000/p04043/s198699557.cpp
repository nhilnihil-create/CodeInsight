//Tanzim bin nasir
#include<bits/stdc++.h>
typedef long long ll;
#define ff first
#define ss second
using namespace std;
void fast()
{
ios::sync_with_stdio(false);
cin.tie(NULL); cout.tie(NULL);
}
ll gcd(ll a,ll b)
{
    if(b==0)
    return a;
    else
    gcd(b,a%b);
}
ll lcd(ll a,ll b)
{
    return (a*b)/gcd(a,b);
}
int main()
{
    int f=0,s=0;
    for(int i=0;i<3;i++)
    {
        int temp;
        cin>>temp;
        if(temp==5)
        f++;
        else if(temp==7)
        s++;
    }
    if(f==2&&s==1)
    cout<<"YES\n";
    else
    cout<<"NO\n";
}
