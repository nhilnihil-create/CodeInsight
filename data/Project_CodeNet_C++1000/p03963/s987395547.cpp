#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll=long long;
using P=pair<int,int>;
int main() {
    int n,k;cin>>n>>k;
    ll co=k;
    for(int i=1;i<n;i++){
        co*=k-1;
    }
    cout<<co<<endl;
}