#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define all(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();
int main(){
    long long N,M;
    cin>>N>>M;
    long long ans;
    if(N>=M/2){
        //Sが余るか丁度
        ans=M/2;
    }else{
        //cが余る
        ans=N;
        //まずSの分全部処理
        M=M-2*N;
        //残ったMが4個あるごとに1個増やせる
        ans=ans+M/4;
    }
    cout << ans << endl;
    return 0;
}