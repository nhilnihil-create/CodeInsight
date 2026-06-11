#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>av(m+1,1);
    vector<int>ttl(m+1,0);
    vector<vector<int> >mtx(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin>>mtx[i][j];
    }
    int ans=n;

    for(int i=0;i<m;i++){
        for(int j=1;j<=m;j++){
            ttl[j]=0;

        }
        for(int j=0;j<n;j++){
            int k=0;
            while(!av[mtx[j][k]]) k++;
            ttl[mtx[j][k]]++;
        }

        int mxi=0;
        for(int j=1;j<=m;j++){
            ///cout<<ttl[j]<<' ';
            if(ttl[j]>ttl[mxi]){
                mxi=j;
            }
        }
        ans=min(ans,ttl[mxi]);
        ///cout<<ans<<'\n';
        av[mxi]=0;
    }

    cout<<ans<<'\n';
    return 0;
}
/**
5 3
0 2 1 4 3
4 4
0 1 2 3

10 4
2 0 1 3 7 5 4 6 8 9
*/
