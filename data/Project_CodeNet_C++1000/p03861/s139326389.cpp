#include<bits/stdc++.h>
//#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;
/*

ll lcm(ll a,ll b)
{
    ll g=__gcd(a,b);
    ll res=(a/g)*b;
    return res;
}
//map<int,pair<int,int>>m;

//ll *arr=new ll[10000000+100];
bool isprime[100000000];
//ll *arr-=new arr[1000000000+5];
void sieve(int n)
{
    isprime[0]=true;
    isprime[1]=true;
    isprime[2]=false;
    for(int i=4;i<=n;i=i+2) isprime[i]=true;
    for(int i=3;i*i<=n;i+=2)
    {
        if(!isprime[i]) //if prime number
        {
            for(int j=i*i;j<=n;j=j+i)
            {
                isprime[j]=true;

            }
        }
    }

}
/*void twinprime()
{
    int c=1;
   // m[0]=make_pair(3,5);
    for(int i=3;i<=18409201;i+=2)
    {
        if((!isprime[i])&&(!isprime[i+2]))
        {
            m[c]=make_pair(i,i+2);
            c++;
        }
    }

}
*/


/*

void NOD(ll n)
{
    //int *arr=new int[n+1];


    for(ll i=1;i<=n;i++)
    {
        for(ll j=i;j<=n;j=j+i)
        {
            arr[j]=arr[j]+1;
        }
    }
    //return arr[n];
}
void SOD(ll n)
{
    int *arr=new int[n+1];


    for(ll i=1;i<=n;i++)
    {
        for(ll j=i;j<=n;j=j+i)
        {
            arr[j]=arr[j]+i;
        }
    }
    //return arr[n];
}
*/


int main()
{

//sieve(18409201);
//   twinprime();
    // NOD(2000000000);
// SOD(1000000000)
    ll a,b,x;

    scanf("%lld %lld %lld",&a,&b,&x);
    ll c=0;
    ll dif=abs((a/x)-(b/x));
    if(a%x==0)
        dif++;
    cout<<dif<<endl;











    return 0;
}
