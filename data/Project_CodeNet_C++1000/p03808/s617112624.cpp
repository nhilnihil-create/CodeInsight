#include <iostream>

using namespace std;

int main(){
    long long N;
    long long A[100000];
    long long diff[100000];
    long long sum_A = 0;
    long long sum_N;
    cin >> N;
    sum_N = N*(N+1)/2;
    for(int i = 0; i < N; i++){
        cin >> A[i];
        sum_A+=A[i];
        if(i >= 1) diff[i] = A[i] - A[i-1];
    }
    diff[0] = A[0] - A[N-1];
    if(sum_A%sum_N != 0){
        cout << "NO" << endl;
        return 0;
    }else{
        long long d = sum_A/sum_N;
        long long cnt = 0;
        for(int i = 0; i < N; i++){
            if((diff[i]-d)%N != 0){
                cout << "NO" << endl;
                return 0;
            }
            if(d-diff[i] < 0){
                cout << "NO" << endl;
                return 0;
            }
            cnt += (d-diff[i])/N;
        }
        if(cnt == d){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}