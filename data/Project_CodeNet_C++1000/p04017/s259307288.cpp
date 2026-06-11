#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100003,INF=1<<30,MAX_LOG=20;

vector<vector<int>> to(MAX,vector<int>(MAX_LOG,0));

int main(){
    
    int N;cin>>N;
    vector<int> X(N);
    for(int i=0;i<N;i++){
        //scanf("%d",&X[i]);
        cin>>X[i];
    }
    
    int L,Q;cin>>L>>Q;
    
    for(int i=0;i<N;i++){
        auto it=upper_bound(all(X),X[i]+L);
        if(it==X.end()){
            if(i!=N-1) to[i][0]=N-1;
            else to[i][0]=INF;
        }else{
            it--;
            to[i][0]=distance(X.begin(),it);
        }
    }
    
    for(int j=1;j<MAX_LOG;j++){
        for(int i=0;i<N;i++){
            if(to[i][j-1]==INF) to[i][j]=INF;
            else to[i][j]=to[to[i][j-1]][j-1];
        }
    }
    
    for(int i=0;i<Q;i++){
        int a,b;cin>>a>>b;
        //scanf("%d",&a);
        //scanf("%d",&b);
        a--;b--;
        if(a>b) swap(a,b);
        
        int ans=0;
        
        while(1){
            auto it=upper_bound(all(to[a]),b);
            if(it==to[a].begin()){
                ans++;
                break;
            }
            it--;
            if(*it==b){
                ans+=(1<<(distance(to[a].begin(),it)));
                break;
            }
            if(it==to[a].begin()&&*it>=b){
                ans++;
                break;
            }
            
            ans+=(1<<(distance(to[a].begin(),it)));
            a=*it;
            
        }
        
        cout<<ans<<"\n";
        
    }
}

