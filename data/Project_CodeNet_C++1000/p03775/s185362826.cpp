#include <iostream>
#include <bitset>
#include <math.h>
using namespace std;

int main() {

    long N;

    cin >> N ;

    long L = sqrt(N) + 1;
    //int L = N / 2; 

    // N = A * B
    // A = N / B
    // B = N / A

    //int A;
    //int B;

    // int a_s = to_string(A).size();
    // int b_s = to_string(B).size();
    // min(a_s, b_s)

    long ans = 100000000000;

    for (long i = 1; i < L ; i++) {

        if (N % i != 0){
            continue;
        }

        long A = i;
        long B = N / i;

        long a_s = to_string(A).size();
        long b_s = to_string(B).size();
        long temp_max = max(a_s, b_s);

        if (ans > temp_max){

            ans = temp_max;
        }
       
    }

    cout << ans << endl;
    
    return 0;

}