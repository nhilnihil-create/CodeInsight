#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int N;
    cin >> N;

    long long ans = N;
    long long max_A = 0;
    long long min_B = 1000000001;

    for (int i = 0; i < N; i++){
        int A, B;
        cin >> A >> B;
        if (A > max_A){
            max_A = A;
            min_B = B;
        }
    }

    cout << max_A + min_B << endl;
}