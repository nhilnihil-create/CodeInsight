#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

 
int main() {
    int n,m;
    cin>>n>>m;
    map<int,int> A,B;
    rep(i,m){
        int a,b;
        cin>>a>>b;
        if(a==1)B[b]=1;
        if(b==n)A[a]=1;
    }
    for(auto p:A){
        if(B[p.first]==1){
            cout<<"POSSIBLE"<<endl;
            return 0;
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
}