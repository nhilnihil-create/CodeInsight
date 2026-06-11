#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    int N,M;
    cin>>N>>M;
    int a[M];
    int b[M];
    rep(i,M){
        cin>>a[i];
        cin>>b[i];
    }
    rep(i,N){
        cout<<count(a,a+M,i+1)+count(b,b+M,i+1)<<endl;
    }
}
