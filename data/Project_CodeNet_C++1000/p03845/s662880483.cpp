
#include<bits/stdc++.h>
#define lln long long int
#define llu unsigned lln
#define sc(n) scanf("%d",&n);
#define scl(n) scanf("%lld",&n);
#define scd(n) scanf("%lf",&n);
#define pf(res) printf("%d\n",res);
#define pfl(res) printf("%lld\n",res);
#define pfd(res) printf("%lf\n",res);
#define maxii 200005
using namespace std;
typedef pair<int,int> pii;
typedef pair<lln,lln> pll;
 vector<int> vi[maxii];
 vector<int>::iterator child;
typedef vector<lln> vl;
typedef vector<pii> vii;
typedef vector<pll> vll;


int arr[maxii];
int arr2[maxii];


int main()
{
    int n;
    cin>>n;
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    int m,x,y;
    sc(m)
    for(int i=0;i<m;i++)
    {
        sc(x)
        sc(y)
        int p=arr[x];
        int sum1=sum-arr[x];
        sum1+=y;
        cout<<sum1<<endl;

    }

}




