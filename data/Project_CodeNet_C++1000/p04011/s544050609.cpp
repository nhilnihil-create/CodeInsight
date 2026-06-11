#include <iostream>
using namespace std;

int main (void) {

    int N, K, X, Y;
    int sum = 0;

     cin >> N >> K >> X >> Y;

     for (int i = 1; i <= N; i++ ){
        if (K >= i) {
            sum += X;
        }else if (K < i){
            sum += Y;
         } 
     }
    cout << sum;


    return 0;
}

