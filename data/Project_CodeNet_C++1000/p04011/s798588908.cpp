#include <iostream>
#include <cmath>


using namespace std;

int main(){
   int N, K, X, Y, result;
   cin>>N;
   cin>>K;
   cin>>X;
   cin>>Y;
    if(N>K){
        cout<< X*K + Y*(N-K);
    }else{
        cout<< X*N;
    }
}

