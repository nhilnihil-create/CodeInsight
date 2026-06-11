#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    int K;
    cin >> K;
    vector<int> A(N+1,0);
    for(int i=1;i<=N;++i)cin>>A[i];
    sort(A.begin(), A.end());
    vector<vector<int>> until(N+2, vector<int>(K+1, 0));
    until[0][0]=1;
    vector<vector<int>> ikou(N+2, vector<int>(K+1, 0));
    ikou[N+1][0]=1;
    for(int i=1;i<=N;++i){
        for(int j=0;j<=K;++j){
            if(until[i-1][j])until[i][j]=1;
            if(until[i-1][j]&&0<=j+A[i]&&j+A[i]<=K)until[i][j+A[i]]=1;
        }
    }
    for(int i=N;i>=1;--i){
        for(int j=0;j<=K;++j){
            if(ikou[i+1][j])ikou[i][j]=1;
            if(ikou[i+1][j]&&0<=j+A[i]&&j+A[i]<=K)ikou[i][j+A[i]]=1;
        }
    }
    int ans=0;
    vector<int> check(5001,-1);
    for(int i=1;i<=N;++i){
        if(A[i]>=K)continue;
        if(check[A[i]]!=-1){
            if(check[A[i]]==0)ans++;continue;
        }
        bitset<5001> buntil;
        for(int j=0;j<=K;++j){
            if(until[i-1][j])buntil.set(j);
        }
        bitset<5001> b;
        for(int j=0;j<=K;++j){
            if(ikou[i+1][j]){
                b|=buntil<<j;
            }
        }
        bool need=0;
        for(int j=max(K-A[i],0);j<K;++j){
            if(b.test(j)){need=1;break;}
        }
        if(!need){ans++;check[A[i]]=0;}
        else check[A[i]]=1;
    }
    cout<<ans<<endl;
    return 0;
}

