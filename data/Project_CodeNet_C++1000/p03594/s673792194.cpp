//unsolved list
//CODE FESTIVAL 2017 qual A-D
#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define C 0.5772156649
#define pi acos(-1.0)
#define ll long long
#define mod 1000000007
#define ls l,m,rt<<1
#define rs m+1,r,rt<<1|1

using namespace std;

const double g=10.0,eps=1e-7;
const int N=500+10,maxn=60000+10,inf=0x3f3f3f;

int n,m,k;
char ans[N][N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=500;i++)
    {
        for(int j=1;j<=500;j++)
        {
            int x=(i+j+1e9)/k,y=(i-j+1e9)/k;
            if(x%2==1&&y%2==1)ans[i][j]='R';
            else if(x%2==1&&y%2==0)ans[i][j]='Y';
            else if(x%2==0&&y%2==1)ans[i][j]='G';
            else ans[i][j]='B';
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            cout<<ans[i][j];
        cout<<endl;
    }
    return 0;
}
/********************

********************/
