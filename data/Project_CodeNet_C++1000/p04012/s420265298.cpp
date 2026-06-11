
#include<bits/stdc++.h>


using namespace std;

typedef long long ll;



bool isprime[10000000+100];
void sieve()
{
    memset(isprime,true,sizeof(isprime));
    isprime[0]=isprime[1]=false;
    for(ll i=2; i*i<=10000000; i++)
    {
        if(isprime[i])
        {
            for(ll j=i*i; j<=10000000; j+=i)
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

   string s;
   cin>>s;
   int freq[26]={};
   for(int i=0;i<s.size();i++)
   {
       freq[s[i]-'a']++;
   }
   bool ans = true;
   for(int i=0;i<26;i++)
   {
       if(freq[i]%2!=0)
       {
           ans=false;
           break;
       }
   }
   if(ans)
   {
       cout<<"Yes\n";
   }
   else
   {
       cout<<"No\n";
   }

}
