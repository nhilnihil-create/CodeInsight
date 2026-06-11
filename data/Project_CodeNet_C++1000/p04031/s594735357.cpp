#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void show(vector<ll>& vc)
{
    for(auto it:vc)cout<<it<<" ";
    cout<<endl;
}
#define M 300014



/**
int marked[M/64 + 2];

#define on(x) (marked[x/64] & (1<<((x%64)/2)))
#define mark(x)  marked[x/64] |= (1<<((x%64)/2))

void bitwiseSieve() {
  for (int i = 3; i * i <=M; i += 2) {
    if (!on(i)) {
      for (int j = i * i; j <= M; j += i + i) {
        mark(j);
      }
    }
  }
}

bool isPrime(int num) {
  return num > 1 && (num == 2 || ((num & 1) && !on(num)));
}
**/


/**
vector<ll>phi(M+2);
bool p[M+2];

void euler_phi(void)
{

    for(ll i=0;i<=M;i++)phi[i]=i;
    memset(p,0,sizeof p);
    p[1]=1;
    p[0]=1;
    phi[1] = 0;

    for(ll i=2; i<=M; i++)
    {

        if(!p[i])
        {

            for(ll j=i; j<=M; j+=i)
            {
                p[j]=1;
                phi[j]/=i;
                phi[j]*=(i-1);

            }
            p[i]=0;
        }
    }


}
//**/


/**
bool p[M+2];
vector<ll>prime;
void seive(void)
{

    memset(p,0,sizeof p);
    p[1]=1;
    p[0]=1;

    for(ll i=4; i<=M; i+=2)
    {
        p[i]=1;

    }

    for(ll i=3; i*i<=M; i+=2)
    {

        if(!p[i])
        {

            for(ll j=i*i; j<=M; j+=2*i)
            {
                p[j]=1;

            }
        }
    }

    prime.push_back(2);
    for(ll i=3; i<=M; i+=2)prime.push_back(i);
}
//**/


/**
ll dx[] = {-1,-1,0,-1,1,0,1,1};
ll dy[] = {-1,0,-1,1,-1,1,0,1};
**/

/**
typedef pair<ll, ll> pii;
#define x first
#define y second


pii extendedEuclid(ll a, ll b)   // returns x, y | ax + by = gcd(a,b)
{
    if(b == 0) return pii(1, 0);
    else
    {
        pii d = extendedEuclid(b, a % b);
        return pii(d.y, d.x - d.y * (a / b));
    }
}

ll modularInverse(ll a, ll n)
{
    pii ret = extendedEuclid(a, n);
    return ((ret.x % n) + n) % n;
}
//**/


/**
ll bigmod(ll a, ll b, ll c)
{
    if(b==0)return 1;
    if(b%2)
    {
        ll p = bigmod(a,b-1,c);
        return (a*p)%c;
    }
    else
    {
        ll p = bigmod(a,b/2,c);
        return (p*p)%c;
    }
}
//**/



void solve(ll t)
{


    ll n;
    cin>>n;
    ll sum =0;
    vector<ll>vc;
    for(int i=0;i<n;i++)
    {
        ll temp;
        cin>>temp;
        vc.push_back(temp);
        sum+=temp;
    }
    ll f = sum/n;
    ll c = (sum+n-1)/n;

    ll ans1 = 0;
    ll ans2 = 0;

    for(auto it:vc)
    {

        ans1+=(it-f)*(it-f);
    }

    for(auto it:vc)
    {

        ans2+=(it-c)*(it-c);
    }

    cout<<min(ans1,ans2)<<endl;




}


int main()
{
//     freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);

    /**seive();        //**/
    /** euler_phi();    //**/
    /** show(phi);      //**/
    /** bitwiseSieve(); //**/





    ll t=1;
    //scanf("%lld",&t);
    ll T=t;



    while(t--)
    {


        solve(T-t);

    }
    return 0;
}
