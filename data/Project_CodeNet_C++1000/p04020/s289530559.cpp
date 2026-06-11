#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<long long> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    long long temp = 0;
    long long ans = 0;
    for(int i = 0; i < N; i++){
        if(A[i] == 0){
            ans += temp / 2;
            temp = 0;
        }
        else temp += A[i];
    }
    ans += temp / 2;
    cout << ans << endl;
}