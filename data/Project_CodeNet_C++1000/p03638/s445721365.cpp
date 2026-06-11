#include <bits/stdc++.h>
#define ll long long
#define inf 100000000000000000
#define mod 1000000007
#define endl '\n'
#define omarshagar                    \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
using namespace std;


int main()
{
    omarshagar
    int n,m;
    cin>>n>>m;
    int k;
    cin>>k;
    int arr[k];
    for(int i=0;i<k;i++)
    {
        cin>>arr[i];
    }
    ll grid[n][m];
    int locr=0;
    int locc=0;
    for(int i=0;i<k;i++)
    {
        int num=arr[i];
        for(;locr<n&&num>0;)
        {
            if(locr%2==0)
            {
                for(;locc<m&&num>0;locc++)
                {
                    num--;
                    grid[locr][locc]=i+1;

                }
                if(locc==m){locc--;locr++;}
            }
            else
            {
                for(;locc>=0&&num>0;locc--)
                {
                    num--;
                    grid[locr][locc]=i+1;
                }
                if(locc==-1){locc++;locr++;}
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int ii=0;ii<m;ii++)
        {
            cout<<grid[i][ii]<<" ";
        }
        cout<<endl;
    }
    return 0;
}