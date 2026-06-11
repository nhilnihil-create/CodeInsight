#include <bits/stdc++.h>

using namespace std;

int main(){
    long long int N;
    cin >> N;
    vector<long long int> A(N),sum(N);
    for(int i=0;i<N;i++){
        cin >> A[i];
    }

    sort(A.begin(),A.end());

    for(int i=0;i<N;i++){
        if(i==0){
            sum[i] = A[i];
        }else{
            sum[i] = sum[i-1] + A[i];
        }
    }

    for(int i=N-1;0<=i;i--){
        if(2*sum[i-1]<A[i]){
            cout << N-i << endl;
            return 0;
        }
    }

    cout << N << endl;
}