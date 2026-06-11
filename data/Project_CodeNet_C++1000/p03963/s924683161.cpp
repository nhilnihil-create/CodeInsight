#include <iostream>
using namespace std;
int main(void){

    int N,K;
    cin >> N >> K;
    long long ways = K;
    
    for(int i=1;i<N;i++){
       ways *= (K-1);
    }
    
    cout << ways;
}