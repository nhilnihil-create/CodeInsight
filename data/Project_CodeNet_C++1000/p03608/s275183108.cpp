#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,r;
    cin >> n >> m >> r;
    vector<int>rr(r);
    
    for(int i=0;i<r;i++)cin >>rr[i];
    sort(rr.begin(),rr.end());
    vector<vector<long> >distance(n+1,vector<long>(n+1,1<<30));
    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        distance[a][b] = c;
        distance[b][a] = c;
    }
for(int k=1;k<=n;k++){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            
                distance[i][j] = min(distance[i][j] , distance[i][k] + distance[k][j]);
            
        }
    }
}
    long ans = 1<<30;

    do{
        long tmp = 0;
        for(int i=0;i<r-1;i++){
            tmp += distance[rr[i]][rr[i+1]];

        }

        ans = min(ans,tmp);

    }while(next_permutation(rr.begin(),rr.end()));

    cout << ans << endl;

}