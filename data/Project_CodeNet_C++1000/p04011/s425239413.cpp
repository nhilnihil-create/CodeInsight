#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,N) for(int i=0; i<N; i++){ ;
int main() {
    int N,K,Y,X;
    cin>>N>>K>>Y>>X;
    if(N<K){
        cout<<Y*N<<endl;
    }
    else
    {
    cout<<K*Y+(N-K)*X<<endl;
    }
}
