#include<bits/stdc++.h>
#define speed_up ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
#define ara(A,N) sort(A,A+N)
#define rev(A,N) sort(A,A+N,greater<long long>())
using namespace std;
int main()
{
    int m, n, i, j, k, l;
    cin>>n>>m;
    vector<string> a(n), b(m);
    for(i = 0; i<n; i++)
    {
        cin>>a[i];
    }
    for(j = 0; j<m; j++)
    {
        cin>>b[j];
    }
    for(i = 0; i<n; i++)
    {
        for(j = 0; j<n; j++)
        {
            if(a[i][j]!= b[0][0]) continue;
            bool x = 1;
            for(k = 0; k<m; k++)
            {
                for(l = 0; l<m; l++)
                {
                    if(i+k>=n || j+l>=n || a[i+k][j+l]!=b[k][l])
                    {
                        x = 0;
                        break;
                    }
                }

            }
             if(x)
                {
                    cout<<"Yes"<<endl;
                    return 0;
                }

        }
    }
    cout<<"No"<<endl;
    return 0;
}





