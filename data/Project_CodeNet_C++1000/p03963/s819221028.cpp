
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
#define maxii 1000005
using namespace std;
typedef pair<int,int> pii;
typedef pair<lln,lln> pll;
vector<lln> vi;
vector<lln>vi2;
vector<lln>vi3;
vector<lln> vl;
vector<pii> vii;
vector<pll> vll;


//int arr[maxii];
//lln arr2[maxii];
//bool check[maxii];
//bool check2[1000][1000];

int arr[maxii];
bool prim[maxii];
int p=0;
void prime()
{
    for(lln i=3;i*i<=maxii;i+=2)
    {
        if(prim[i]==false)
        {
            for(lln j=i*i;j<=maxii;j+=i+i)
            {
                prim[j]=true;
            }
        }
    }
    arr[p++]=2;
    for(int i=3;i<=maxii;i+=2)
    {
        if(prim[i]==false)
        {
            arr[p++]=i;
        }
    }
}
int pp;
void fact(lln n)
{
    for(int i=0;i<p && arr[i]*arr[i]<=n;i++)
    {
        if(n%arr[i]==0)
        {
            vi3.pb(arr[i]);
            while(n%arr[i]==0)
            {
                n/=arr[i];
            }
        }
    }
    if(n>1)
    {
        vi3.pb(n);
    }
}
int g=0;
lln cal(lln nn)
{
    //nn;
    //cout<<"first:"<<endl;
    for(int i=0;i<vi3.size() && vi3[i]<=nn;i++)
    {
        //cout<<nn<<" "<<endl;
        if(nn%vi3[i]==0)
        {
            //lln d=arr2[i]-1;
            nn/=vi3[i];
            nn*=(vi3[i]-1);
        }
    }
    return nn;
}
int main()
{
  int n,k;
  cin>>n>>k;
  int sum=k;
  k--;
  n--;
  for(int i=0;i<n;i++)
  {
      sum*=k;
  }
  cout<<sum;
}




