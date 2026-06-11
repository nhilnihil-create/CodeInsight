#include <iostream>
#include <vector>
#include <math.h>
using namespace std;


int main(void){
    long long N;
    cin >> N;
    long f = log10(N)+1;
    
    for(long i=1; i*i<=N; i++){
        if(N%i==0){
            if(log10(N/i)+1<f)f=log10(N/i)+1;
        }
    }
    cout << f << endl;
    
}
