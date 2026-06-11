#include<bits/stdc++.h>


using namespace std;

typedef long long ll;

const int N = 1000000;
bool isprime[N+1];
#define eps 1e-9
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
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    int n;
    string s;
    cin>>s;
    n = s.size();
    ll ans = 0;
    for(int i=0;i<(1<<(n-1));i++)
    {
        ll res = 0;
        for(int j=0;j<n-1;j++)
        {
            res = res*10 + s[j]-'0';
            if(i & (1<<j))
            {
                ans+=res;

                res = 0;
            }
        }

        ans += res*10 + s[n-1]-'0';

    }
    cout<<ans<<endl;


}

