#include<bits/stdc++.h>
using namespace std;
const int mxn = 303;
bool vis[mxn][mxn];
long long  mat[mxn][mxn] , given[mxn][mxn];
int n;
void f()
{
    for(int k= 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(mat[i][j] > mat[i][k]+mat[k][j])
                {
                    mat[i][j] = mat[i][k] + mat[k][j];
                    vis[i][j] = true;
                }
                else if(mat[i][j] ==  mat[i][k]+mat[k][j] && k!=i && k!=j)
                {
                    vis[i][j] = true;
                }
            }
        }
    }
}
int main()
{
    cin>>n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin>>given[i][j];
            mat[i][j] = given[i][j];
        }
    }
    memset(vis , false ,sizeof vis);
    f();
    bool flag = true;
    for(int i = 1 ; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(mat[i][j]!= given[i][j]) {flag = false ; break;}
        }
    }
    if(flag)
    {
        long long tot_cnt = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(!vis[i][j]) tot_cnt += given[i][j];
            }
        }
        cout<<tot_cnt/2<<endl;
    }
    else
    cout<<-1<<endl;
    return 0;
}
