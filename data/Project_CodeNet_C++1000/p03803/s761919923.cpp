
#include<bits/stdc++.h>
#define lln long long int
#define llu unsigned lln
#define sc(n) scanf("%d",&n);
#define scl(n) scanf("%lld",&n);
#define scd(n) scanf("%lf",&n);
#define pf(res) printf("%d\n",res);
#define pfl(res) printf("%lld\n",res);
#define pfd(res) printf("%lf\n",res);
#define maxii 100005
using namespace std;
typedef pair<int,int> pii;
typedef pair<lln,lln> pll;
vector<int> vi[maxii];
vector<int>:: iterator child;
typedef vector<lln> vl;
typedef vector<pii> vii;
typedef vector<pll> vll;


int arr[maxii];
int arr2[maxii];
bool check[maxii];
int cnt=0,n;
void dfs(int node)
{
    check[node]=true;
    if(vi[node].size()==n-1)cnt++;
    for(int child=0;child<vi[node].size();child++)
    {
        if(check[vi[node][child]]==false)
        {
            dfs(vi[node][child]);
        }
    }
}

int main()
{
    int a,b;
    cin>>a>>b;
    if(a==1)a=14;
    if(b==1)b=14;
    if(a==b)cout<<"Draw";
    else if(a>b)cout<<"Alice";
    else cout<<"Bob";

}




