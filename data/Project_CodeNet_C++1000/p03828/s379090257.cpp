#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define bug printf("bug\n");
#define bug2(var) cout<<#var<<" "<<var<<endl;
#define co(q) cout<<q<<endl;
#define all(q) (q).begin(),(q).end()
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e6;
#define pi acos(-1)
#define inf 1000000000000000LL
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
bool prime[MAX];
int prime_numbers[9999999],pos;
void sieve()
{
    prime[0]=1;
    prime[1]=1;
    for(int i=4; i<=MAX; i+=2)
        prime[i]=1;
    int root = sqrt(MAX);
    for(int i=3; i<=root; i+=2)
    {
        if(prime[i]==0)
        {
            for(int j=i*i; j<=MAX; j+=i)
            {
                prime[j]=1;
            }
        }
    }
    prime_numbers[pos++]=2;
    for(int i=3; i<MAX; i+=2)
        if(prime[i]==0)
            prime_numbers[pos++]=i;
}
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    sieve();
    ll n,ans=1;
    cin>>n;

    for(int i=0; i<pos; i++)
    {
        if(prime_numbers[i]>n)
            break;
        ll cur=n,p=prime_numbers[i],cnt=0;
        while(p<=cur)
        {
            cnt+=cur/p;
            p*=prime_numbers[i];
        }
        if(cnt)
        {
            ans=(ans*(cnt+1))%MOD;
        }
    }
    cout<<ans<<endl;

    return 0;
}
