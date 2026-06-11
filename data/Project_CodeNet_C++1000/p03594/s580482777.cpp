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
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>k;
    string s[2];
    s[0]="RB";s[1]="GY";
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            int x=(i+j+1e9)/k,y=(i-j+1e9)/k;
            cout<<s[x%2][y%2];
        }
        cout<<endl;
    }
    return 0;
}
/********************

********************/
