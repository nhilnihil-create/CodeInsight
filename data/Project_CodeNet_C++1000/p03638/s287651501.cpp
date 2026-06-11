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
int mat[200][200];
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    int r,c,n,x=1,y=1,f=0;
    cin>>r>>c>>n;
    for(int i=1; i<=n; i++)
    {
        int a;
        cin>>a;
        while(a--)
        {
            mat[x][y]=i;
            if(!f)
                y++;
            else
                y--;
            if(y>c)
            {
                x++;
                f^=1;
                y=c;
            }
            else if(y==0){
                y=1;
                x++;
                f^=1;

            }
        }
    }
    for(int i=1; i<=r; i++)
    {
        for(int j=1; j<=c; j++)
        {
            cout<<mat[i][j];
            if(j!=c)
                cout<<" ";
        }
        cout<<endl;
    }

    return 0;
}
