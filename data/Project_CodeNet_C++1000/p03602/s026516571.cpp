#include<bits/stdc++.h>
using namespace std;
#define MX 309
#define inf 1e15+5
long long n;
long long g[MX][MX];
long long d[MX][MX];
bool v[MX][MX];
void fw(int n)
{

    for(int k=0; k<n; k++)
    {
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
            {
                d[i][j]=min(d[i][k]+d[k][j],d[i][j]);
            }
    }

    for(int i=0;i<n;i++){

        for(int j=0;j<n;j++){

            if(d[i][j]!=g[i][j]){

                cout<<-1<<endl;
                return;

            }
        }

    }

    for(int k=0; k<n; k++)
    {
        for(int i=0; i<n; i++)

            for(int j=0; j<n; j++)
            {
                long long x=g[i][j];
                long long y=g[i][k]+g[k][j];
                if(i!=k && j!=k && x==y) v[i][j]=v[j][i]=true;

            }
    }

    long long ans=0;
    for(int i=0;i<n;i++){

        for(int j=0;j<n;j++){
            if(v[i][j]!=true)
            {
                ans+=g[i][j];
            }
        }

    }

    cout<< ans/2 <<endl;
return;
}

int main()
{


        cin>>n;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                {
                cin>>g[i][j];
                d[i][j]=g[i][j];
                }
        fw(n);
        return 0;

}
