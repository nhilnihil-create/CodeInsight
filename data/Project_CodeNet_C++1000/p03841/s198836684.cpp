#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100001,INF=1<<30;

int main(){
    
    int N;cin>>N;
    vector<int> A(N*N,0);
    vector<pair<int,int>> S(N);
    for(int i=0;i<N;i++){
        cin>>S[i].first;
        S[i].first--;
        S[i].second=i;
        A[S[i].first]=i+1;
    }
    
    sort(all(S));
    
    bool ok=true;
    int right=0;
    
    for(int i=0;i<N;i++){
        int a=S[i].first,b=S[i].second,cnt=0;
        int start=right;
        for(int j=start;j<a;j++){
            if(cnt>=b) break;
            right++;
            if(A[j]==0){
                A[j]=b+1;
                cnt++;
            }
        }
        if(cnt<b) ok=false;
    }
    
    for(int i=0;i<N;i++){
        int a=S[i].first,b=S[i].second,cnt=0;
        for(int j=a+1;j<N*N;j++){
            if(cnt>=N-b-1) break;
            if(A[j]==0){
                A[j]=b+1;
                cnt++;
            }
        }
    }
    
    for(int i=0;i<N*N;i++){
        if(A[i]==0) ok=false;
    }
    
    if(ok){
        cout<<"Yes"<<endl;
        for(int i=0;i<N*N;i++){
            if(i) cout<<" ";
            cout<<A[i];
        }
        cout<<endl;
    }else cout<<"No"<<endl;
    
}


