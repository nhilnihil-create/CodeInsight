#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define all(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();
int main(){
    int N;
    long long K;
    cin>>N>>K;
    map<long long,long long> p;
    long long a,b;
    rep(i,N){
        cin>>a>>b;
        if(p.count(a)){
            p[a]+=b;
        }else{
            p[a]=b;
        }
    }
    for(auto ab:p){
        if(K<=ab.second){
            cout << ab.first << endl;
            return 0;
        }else{
            K-=ab.second;
        }
    }
    return 0;
}