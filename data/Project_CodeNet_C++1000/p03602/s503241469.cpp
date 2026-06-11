#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=301,INF=1<<30;
ll S[MAX][MAX],T[MAX][MAX];
int use[MAX][MAX];
int N;

void floyd(){
    for(int k=0;k<N;k++){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                T[i][j]=min(T[i][j],T[i][k]+T[k][j]);
            }
        }
    }
}

void check(){
    for(int k=0;k<N;k++){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(T[i][k]==0) continue;
                if(T[k][j]==0) continue;
                if(T[i][j]==T[i][k]+T[k][j]) use[i][j]=1;
            }
        }
    }
}

int main(){

  cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>S[i][j];
            T[i][j]=S[i][j];
        }
    }
    
    floyd();
    
    bool ok=true;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(S[i][j]!=T[i][j]) ok=false;
        }
    }
    
    if(!ok) cout<<-1<<endl;
    else{
        check();
        
        ll ans=0;
        
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(use[i][j]==0) ans+=T[i][j];
            }
        }
        
        cout<<ans/2<<endl;
    }
    
}
