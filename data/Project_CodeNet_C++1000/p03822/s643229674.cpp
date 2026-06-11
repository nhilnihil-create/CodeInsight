#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100003,INF=1<<30;
vector<int> S[MAX];
int need[MAX];

int solve(int u){
    vector<int> T;
    for(int i=0;i<S[u].size();i++){
        int a=S[u][i];
        if(need[a]!=-1) T.push_back(need[a]);
        else T.push_back(solve(a));
    }
    
    if(T.size()==0) return need[u]=0;
    sort(all(T));
    int ans=0;
    for(int i=0;i<T.size();i++){
        ans=max(ans,T[i]+int(T.size())-i);
    }
    return need[u]=ans;
}

int main(){
    
    int N;cin>>N;
    
    for(int i=0;i<N;i++){
        need[i]=-1;
    }
    
    for(int i=0;i<N-1;i++){
        int a;cin>>a;
        a--;
        S[a].push_back(i+1);
    }
    
    cout<<solve(0)<<endl;
    
}

