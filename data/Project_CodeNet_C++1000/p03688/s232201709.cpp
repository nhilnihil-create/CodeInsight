#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
int main(){
    int n;
    cin>>n;
    vector<int> A(n);
    rep(i,n) cin>>A[i];
    sort(A.begin(),A.end());
    if(A[n-1]-A[0]>1){
        cout<<"No";
    }
    if(A[n-1]-A[0]==1){
        int a=0;
        rep(i,n) if(A[i]==A[0]) a++;
        if(a<A[n-1]&&A[n-1]<=a+(n-a)/2) cout<<"Yes";
        else cout<<"No";
    }
    if(A[n-1]==A[0]){
        if(A[0]==n-1||A[0]<=n/2) cout<<"Yes";
        else cout<<"No";
    }
}