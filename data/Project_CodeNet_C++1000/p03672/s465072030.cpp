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


char arr[maxii];
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
    string a;
    cin>>a;
    int len=a.size();
    int c=0;
    int ans=0;
    int r=1;
    for(int i=len-1;i>=0;i-=2)
    {
        int p=i/2;
        c=0;
        for(int j=0,k=p;j<p;j++,k++)
        {
            if(a[j]!=a[k])
            {
                c=1;
                break;
            }
        }
        if(c==0)
        {
            ans=r*2;
            break;
        }
        r++;
    }
    cout<<len-ans;

}




