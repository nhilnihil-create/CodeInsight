
#include<bits/stdc++.h>


using namespace std;

typedef long long ll;

#define pi 2*acos(0.0)
#define eps 1e-9
const int N = 1e7+1;
bool isprime[N];

void sieve()
{
    memset(isprime,true,sizeof(isprime));
    isprime[0]=isprime[1]=false;

    for(ll i=2; i*i<=N; i++)
    {
        if(isprime[i])
        {
            for(ll j=i*i; j<=N; j+=i)
            {
                isprime[j]=false;
            }
        }
    }
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    string a,b;
    cin>>a>>b;
    if(a.size()==b.size())
    {
        if(a>b)
        {
            cout<<"GREATER\n";
        }
        else if(a<b)
        {
            cout<<"LESS\n";
        }
        else
        {
            cout<<"EQUAL\n";
        }
    }
    else if(a.size()>b.size())
    {
        cout<<"GREATER\n";
    }
    else
    {
        cout<<"LESS\n";
    }


}


