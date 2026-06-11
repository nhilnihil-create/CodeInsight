#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N);
    for(int i=0;i<N;i++){
        cin >> A[i];
    }
    sort(A.begin(),A.end());
    ll sum[N+1];
    sum[0] =0;
    ll canNotNum =0;
    for(int i=0;i<N-1;i++){
        sum[i+1] = sum[i] + A[i];
        if(sum[i+1]*2 < A[i+1]){
            // cerr << "can Not A[i]=" << A[i] <<"sum=" <<sum[i+1] << endl; 
            canNotNum = (i+1);
        }
    }
    cout << N- canNotNum << endl;

    return 0;
}