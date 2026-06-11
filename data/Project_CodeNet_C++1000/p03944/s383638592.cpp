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
int mat[105][105],r,c,n;
void paint1(int x)
{
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<x; j++)
            mat[i][j]=1;
    }
}
void paint2(int x)
{
    for(int i=0; i<r; i++)
    {
        for(int j=x; j<c; j++)
            mat[i][j]=1;
    }
}
void paint3(int y)
{
    for(int i=0; i<c; i++)
    {
        for(int j=0; j<y; j++)
            mat[j][i]=1;
    }
}
void paint4(int y)
{
    for(int i=0; i<c; i++)
    {
        for(int j=y; j<r; j++)
            mat[j][i]=1;
    }
}
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    cin>>c>>r>>n;
    for(int i=0; i<n; i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        if(z==1)
            paint1(x);
        else if(z==2)
            paint2(x);
        else if(z==3)
            paint3(y);
        else
            paint4(y);
    }
    int cnt=0;
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            if(!mat[i][j])
                cnt++;
    cout<<cnt<<endl;

    return 0;
}
