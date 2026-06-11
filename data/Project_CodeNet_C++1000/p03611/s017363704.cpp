#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
    long long N;
    cin >> N;
    vector<long long> A(N);
    rep(i,N)cin>>A[i];

    vector<long long> Vals(100001, 0);
    rep(i,N){
        long long val = A[i];
        Vals[val] += 1;
        if(val>1)Vals[val-1]+=1;
        if(val<100000)Vals[val+1]+=1;
    }

    long long ans = *max_element(Vals.begin(), Vals.end());
    cout << ans << endl;
    return 0;

}