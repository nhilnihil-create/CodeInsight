/*Always success does not build on success,success build on failure and hardwork*/
#include <bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define vec         vector<int>
#define map         map<int,int>
#define scn(t)      scanf("%d",&t);
#define lscn(t)      scanf("%lld",&t);
#define mod         1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
#define endl        "\n"
using namespace std;
const int N=2e5+5;

int main()
{
    int n;
    scn(n);

    int sum=0;

    int arr[n];

    rep(i,0,n)
    {
        scn(arr[i]);

        sum=sum+arr[i];
    }

    int k1=sum/n,k2=sum/n+1;

    int ans1=0,ans2=0;

    for(int i=0;i<n;i++)
    {
        ans1+=(k1-arr[i])*(k1-arr[i]);
    }

    for(int i=0;i<n;i++)
    {
        ans2+=(k2-arr[i])*(k2-arr[i]);
    }

    cout<<min(ans1,ans2)<<endl;
}

