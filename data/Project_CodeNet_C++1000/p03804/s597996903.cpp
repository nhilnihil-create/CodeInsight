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
string x[100],y[100];
int n,m;
bool test(int a,int b)
{
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(y[i][j]!=x[i+a][j+b])
                return 0;
        }
    }
    return 1;
}
void check(int pos)
{
    for(int i=0; i<=n-m; i++)
    {
        if(test(pos,i)){
            cout<<"Yes"<<endl;
            exit(0);
        }
    }
}
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    cin>>n>>m;
    for(int i=0; i<n; i++)
        cin>>x[i];
    for(int i=0; i<m; i++)
        cin>>y[i];
    for(int i=0;i<=n-m;i++)
        check(i);


    cout<<"No"<<endl;
    return 0;
}
