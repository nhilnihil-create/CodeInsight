#include<bits/stdc++.h>
using namespace std;
#define ll  long long
#define endl '\n'
#define FASTINOUT ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const ll mod = 1000000007;
const double PI = 3.141592653589793238463;
const int N=4e5+100;
int main()
{
    FASTINOUT;
    int r,c;
    cin>>r>>c;
    int ans[r][c];
    int m;
    cin>>m;
    pair<int,int>p[m];
    for (int i=0;i<m;i++)
    {
        cin>>p[i].first;
        p[i].second=i+1;
    }
    sort(p,p+m);
    reverse(p,p+m);
    int pos=0,i=0,j=0;
    while (pos<m){
        int cnt=0;
        while (cnt<p[pos].first){
            if (i%2==0)
            {
                ans[i][j++]=p[pos].second;
            }
            else{
                ans[i][j--]=p[pos].second;
            }
            if (j==-1 ||j==c){
                i++;
                if (j==c)
                    j--;
                if (j==-1)
                    j++;
            }
            cnt++;
        }
        pos++;
    }
    for (int i=0;i<r;i++){
        for (int j=0;j<c;j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
