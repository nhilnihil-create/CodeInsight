#include <bits/stdc++.h>
using namespace std;

int main(){
    long long N,A,B;
    cin >> N >> A >> B;
    vector<long long> X;
    for(int i=0; i<N; i++){
        long long j;
        cin >> j;
        X.push_back(j);
    }
    sort(X.begin(), X.end());
    long long sum=0;
    for(int i = 0; i < N-1; i++){
        long long distance = X[i+1] - X[i];
        if(distance*A < B){
            sum += distance*A;
        }else{
            sum += B;
        }
    }
    cout << sum << endl;
}