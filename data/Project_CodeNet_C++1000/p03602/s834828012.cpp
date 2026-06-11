#include<bits/stdc++.h>

using namespace std;
#define MXX 305
typedef pair<int,int> ii;
vector<ii> adj[1000];
vector<int> t_adj[1000];
bool visited[1000];
long long adj_mat[MXX][MXX];


void add_edge(int u,int v,int c)
{
    adj[u].push_back(ii(c,v));
    adj[v].push_back(ii(c,u));

}

bool flag[MXX][MXX];

void floydwarshall(int n)
{

    for(int k=0; k<n; k++)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(adj_mat[i][k]+adj_mat[k][j]<adj_mat[i][j])
                {
                    adj_mat[i][j]=adj_mat[i][k]+adj_mat[k][j];
                }
                else if(adj_mat[i][k]+adj_mat[k][j]==adj_mat[i][j] && i!=k && j!=k)
                {
                    flag[i][j]=true;
                }
            }
        }
    }
}

int main()
{
    int n;
    long long ans=0;

        cin>>n;
        int mat[n][n];
     for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cin>>mat[i][j];
                adj_mat[i][j]=mat[i][j];
            }
        }

        floydwarshall(n);
        bool f=false;
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {

                if(adj_mat[i][j]!=mat[i][j])
                {
                    f=true;
                    break;
                }
                else if(!flag[i][j])
                ans+=adj_mat[i][j];
            }
        }
        if(f)
        cout<<-1<<endl;
        else cout<<ans<<endl;
}
