#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=200001,INF=1<<30;

int par[MAX];

void init(int n){
    for(int i=0;i<n;i++){
        par[i]=i;
    }
}

int root(int a){
    if(par[a]==a) return a;
    else return par[a]=root(par[a]);
}

void unite(int a,int b){
    if(root(a)!=root(b)) par[root(b)]=root(a);
}

bool check(int a,int b){
    return root(a)==root(b);
}



int main(){
    
    int N,K,L;cin>>N>>K>>L;
    vector<int> S(N),T(N);
    
    init(N);
    
    for(int i=0;i<K;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        unite(a,b);
    }
    
    for(int i=0;i<N;i++){
        S[i]=root(i);
    }
    
    init(N);
    
    for(int i=0;i<L;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        unite(a,b);
    }
    
    for(int i=0;i<N;i++){
        T[i]=root(i);
    }
    
    map<pair<int,int>,int> M;
    
    for(int i=0;i<N;i++){
        M[make_pair(S[i],T[i])]++;
    }
    
    for(int i=0;i<N;i++){
        if(i) cout<<" ";
        cout<<M[make_pair(S[i],T[i])];
    }
    
    cout<<endl;
    
}
