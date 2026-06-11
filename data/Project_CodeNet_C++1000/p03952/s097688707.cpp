#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define INF 1e9
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

void solve(int N,int x){
    if(x<=1 || x>=N*2-1){
        cout<<"No"<<endl;
        return;
    }
    cout<<"Yes"<<endl;
    vector<int> res(N*2-1,-1);
    res[N-2]=1;
    res[N-1]=x;
    res[N]=N*2-1;
    int iter=0;
    for(int v=2;v<N*2-1;v++){
        if(v==x) continue;
        while(res[iter]!=-1) iter++;
        res[iter]=v;
    }
    for(auto v : res) cout<<v<<endl;
}


int main(){
    int N,x;
    cin>>N>>x;
    solve(N,x);
}