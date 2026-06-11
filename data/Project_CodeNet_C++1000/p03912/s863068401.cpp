#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+7;
vector<int> G[N];
int a[N];
int main()
{
    int m,k,n,x;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        a[x%m]++;
        G[x%m].push_back(x);
    }
    int ans=a[0]/2;
    for(int i=1;i<=m/2;i++){
        if(i != m-i)
        {
            x = min(a[i], a[m-i]);
            ans += x;
            a[i] -= x;
            a[m-i] -= x;
        }
        else {
            ans+=a[i]/2;
            a[i]=0;
        }
    }
    //cout<<ans<<endl;
    int l,tmp;
    for(int i=1;i<m;i++){
        if(a[i] > 1){
            tmp = 0;
            sort(G[i].begin(), G[i].end());
            l = G[i].size();
            for(int j=0;j<l-1;j++){
                if(G[i][j] == G[i][j+1]){
                    tmp ++;
                    j++;
                }
            }
            ans += min(a[i]/2, tmp);
        }
    }
    printf("%d\n",ans);
    return 0;
}
