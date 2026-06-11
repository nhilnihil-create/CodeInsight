#include <bits/stdc++.h>
#include <vector>
#include <set>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
    long long N;
    cin >> N;
    vector<long long> A(N,0);
    rep(i,N)cin>>A[i];

    sort(A.begin(),A.end());
    
    long long pre = A[0];
    long long ans = 0;
    long long count = 1;

    rep(i,N){
        if(i==0)continue;

        long long val = A[i];
        if(val != pre){
            ans += count%2;
            count = 1;
        }else{
            count++;
        }
        pre = val;
    }
    ans += count%2;

    cout << ans << endl;
    return 0;
}