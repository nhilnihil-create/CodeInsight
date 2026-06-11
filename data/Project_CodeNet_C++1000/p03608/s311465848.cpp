#include<bits/stdc++.h>
using namespace std;

long long d[200][200];

void warshall_floyd(int n) {
  for (int k = 0; k < n; k++){       
    for (int i = 0; i < n; i++) {    
      for (int j = 0; j < n; j++) {  
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
}

int main(){
    for(int i=0;i<200;++i){
        for(int j=0;j<200;++j){
            if(i==j)d[i][j]=0;
            else d[i][j]=1e18;
        }
    }
    int n,m,r;cin>>n>>m>>r;
    vector<int>R(r);
    for(int i=0;i<r;++i){
        cin>>R[i];
        R[i]--;
    }
    sort(R.begin(),R.end());
    for(int i=0;i<m;++i){
        long long a,b,c;
        cin>>a>>b>>c;
        a--;b--;
        d[a][b]=c;
        d[b][a]=c;
    }
    warshall_floyd(n);
    long long ans=1e18;
    do{
        long long sum=0;
        for(int i=1;i<r;++i){
            sum+=d[R[i-1]][R[i]];
        }
        ans=min(ans,sum);
    }while(next_permutation(R.begin(),R.end()));
    cout<<ans<<endl;
}
