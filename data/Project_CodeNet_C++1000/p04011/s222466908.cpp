#include <iostream>
using namespace std;

int main (void) {

    int N, K, X, Y;
    int sum = 0;

     cin >> N >> K >> X >> Y;

     for (int i = 1; i <= N; i++ ){

        if (N > K) {

            sum = ((K * X) + (N - K) * Y) ;
        
        }else {
            
            sum = N * X;
         
         } 
     }

    cout << sum << endl;


    return 0;
}

