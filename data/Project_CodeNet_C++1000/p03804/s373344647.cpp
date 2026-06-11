#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{

    int n,m;
    cin >> n >> m;
    char mat[n+10][n+10],ara[m+10][m+10];

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            cin >> mat[i][j];
    }
    for(int i=0; i<m; i++)
        {for(int j=0; j<m; j++)
            {cin >> ara[i][j];}
        }


    //int si=0,sj=0;
    bool ans = 0, mrk = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(ara[0][0]==mat[i][j] && i+m-1<n && j+m-1<n)
            {
                mrk = 0;
                for(int ki = i,si=0; si<m; si++,ki++)
                {
                    for(int kj = j,sj=0; sj<m; sj++,kj++)
                    {
                        if(ara[si][sj]==mat[ki][kj])
                        {

                        }
                        else
                        {
                            mrk = 1;
                            break;
                        }
                    }
                    if(mrk)break;
                }
                if(!mrk)
                {
                    ans = 1;
                    break;
                }
//                si = 0, sj = 0;
                mrk = 0;

            }
        }
        if(ans ==1)
            break;
    }
    if(ans)
    {
        cout << "Yes" << endl;
    }
    else
        cout << "No" << endl;







}
