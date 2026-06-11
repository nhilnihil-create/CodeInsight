#include <bits/stdc++.h>

#include <fstream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

typedef long long ll;
typedef long double ld;
using namespace std;
#define endl "\n"
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
using namespace __gnu_pbds;
const int N=100+5, mxN=(1<<22);
int mod=1e9+7;
 int ans[N][N];
 int arr[N*N];

int main()
{
    FIO
    int row,col;
    cin>>row>>col;
    int n;
    cin>>n;
    int x=0,y=0;
    for(int i=0;i<n;i++)
    {
        int t;
        cin>>t;
        while(t--)
        {
            ans[x][y]=i;
            if(x%2==0)
            {
                if(y<col-1)
                {
                    y++;
                }
                else x++;

            }
            else
            {
                if(y>0)
                    y--;
                else
                    x++;

            }

        }

    }
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cout<<ans[i][j]+1<< " ";
        }
        cout<<endl;


    }

    return 0;

}




