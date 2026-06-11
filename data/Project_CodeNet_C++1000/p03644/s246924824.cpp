#include<bits/stdc++.h>
#define lln long long int
#define llu unsigned lln
#define sc(n) scanf("%d",&n);
#define scl(n) scanf("%lld",&n);
#define scd(n) scanf("%lf",&n);
#define pf(res) printf("%d\n",res);
#define pfl(res) printf("%lld\n",res);
#define pfd(res) printf("%lf\n",res);
#define pb(n) push_back(n);
#define maxii 200005
using namespace std;
typedef pair<int,int> pii;
typedef pair<lln,lln> pll;
vector<int> vi;
vector<lln> vl;
vector<pii> vii;
vector<pll> vll;


llu arr[maxii];
llu arr2[maxii];
//bool check[maxii];
bool check2[1000][1000];
//lln n,m;
llu gcd(llu a,llu b)
{
    if(b==0){
      return a;
     }
    return gcd(b,a%b);
}


int main()
{
    int n;
    cin>>n;
    if(n==1){cout<<1;return 0;}
    int maxi=0,ans=0;
    for(int i=2;i<=n;i++)
    {
        int p=i;
        int res=0;
        while(p%2==0)
        {
            p/=2;
            res++;
        }
        if(maxi<=res)
        {
            ans=i;
            maxi=res;
        }
    }
    cout<<ans;

}




