#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int N, K, j, x, sum = 0;
    cin >> N >> K;
    
    for(j = 0; j < N; j++){
        cin >> x;
        
        if(x <= K - x)
        sum = sum + (2 * x);
        
        else
        sum = sum + 2 * (K - x);
    }
    cout << sum << endl;
}
