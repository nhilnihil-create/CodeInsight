#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100001,INF=1<<30;

int main(){

  string S,T;cin>>S>>T;
    int N=S.size(),M=T.size();
    
    vector<int> ScntA(N+1,0),TcntA(M+1,0),ScntB(N+1,0),TcntB(M+1,0);
    
    for(int i=0;i<N;i++){
        if(S[i]=='A'){
            ScntA[i+1]=ScntA[i]+1;
            ScntB[i+1]=ScntB[i];
        }else{
            ScntA[i+1]=ScntA[i];
            ScntB[i+1]=ScntB[i]+1;
        }
    }
    
    for(int i=0;i<M;i++){
        if(T[i]=='A'){
            TcntA[i+1]=TcntA[i]+1;
            TcntB[i+1]=TcntB[i];
        }else{
            TcntA[i+1]=TcntA[i];
            TcntB[i+1]=TcntB[i]+1;
        }
    }
    
    int Q;cin>>Q;
    
    for(int i=0;i<Q;i++){
        int a,b,c,d;cin>>a>>b>>c>>d;
        a--;c--;
        
        int x=(ScntA[b]-ScntA[a]+300000-(ScntB[b]-ScntB[a]))%3;
        int y=(TcntA[d]-TcntA[c]+300000-(TcntB[d]-TcntB[c]))%3;
        if(x==y) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
