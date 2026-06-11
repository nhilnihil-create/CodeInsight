#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=305;
ll N,d[MAX][MAX],pos[MAX][MAX],fin;
int main(){
    scanf("%lld",&N);
    for(int i=0;i<N;i++) for(int j=0;j<N;j++) scanf("%lld",&d[i][j]);
    for(int k=0;k<N;k++) for(int i=0;i<N;i++) for(int j=0;j<N;j++) if(i!=j&&j!=k&&k!=i){
        if(d[i][j]>d[i][k]+d[k][j]){
            printf("-1\n");
            return 0;
        }
        if(d[i][j]==d[i][k]+d[k][j]){
            pos[i][j]=1;
        }
    }
    for(int i=0;i<N;i++) for(int j=i+1;j<N;j++) if(!pos[i][j]) fin+=d[i][j];
    printf("%lld\n",fin);
}
