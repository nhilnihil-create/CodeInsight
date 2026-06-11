#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
    int N; cin>>N;
    set<int> A;

    int ans=0;
    rep(i,N){
        int a; cin>>a;
        if(A.count(a)){
            A.erase(a);
            ans--;
        }else{
            A.insert(a);
            ans++;
        }
    }
    cout << ans << endl;


    // vector<int> A(1e9+1,0);

    // int ans=0;
    // rep(i,N){
    //     int a; cin>>a;
    //     if(A[a]==0){
    //         A[a]=1;
    //         ans++;
    //     }else if(A[a]==1){
    //         A[a]=0;
    //         ans--;
    //     }
    // }

    // // int ans=0;
    // // for(int x:A){
    // //     ans += x;
    // // }
    // cout << ans << endl;
}
