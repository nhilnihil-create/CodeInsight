#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
bool isprime[100000 + 10];
ll ans;
void sieve(int n)
{
    memset(isprime,true,sizeof(isprime));

    isprime[1]=isprime[0]=false;
    for(int i=2; i*i<=n; i++)
    {
        if(isprime[i])
        {
            ans=i;

            for(int j=i*i; j<=n; j+=i)
            {
                isprime[j]=false;
            }
        }
    }


}


int main(void)
{
  ll a,b,x;
  cin>>a>>b>>x;


  ll i,j;
   i = b/x;
   j = a/x;


  ll ans = i-j;
  if(a%x==0)
  {
      ans++;
  }

  cout<<ans<<endl;

}





