#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=2001,INF=1<<30;

int main(){
    
    int N;cin>>N;
    vector<int> A(N),S(100,0);
    for(int i=0;i<N;i++){
        cin>>A[i];
        S[A[i]]++;
    }
    sort(all(A));
    bool flag=true;
    if(A[0]*2<A[N-1]) flag=false;
    if(N!=2&&A[0]==A[1]&&A[0]==1) flag=false;
    if(A[N-2]!=A[N-1]) flag=false;
    
    if(N==2){
        if(A[0]!=1||A[1]!=1) flag=false;
    }
    else{
        for(int i=1;i<N-1;i++){
            if(S[i-1]&&S[i+1]&&!S[i]) flag=false;
        }
        if(A[0]==A[2]) flag=false;
        if(A[N-1]<=A[0]*2-2) flag=false;
        if(A[0]==A[1]&&A[N-1]==A[0]*2) flag=false;
    }
    if(flag) cout<<"Possible"<<endl;
    else cout<<"Impossible"<<endl;
}
