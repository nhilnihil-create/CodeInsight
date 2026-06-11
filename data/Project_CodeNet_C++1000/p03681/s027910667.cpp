#include <iostream>
#include <cstdio>
using namespace std;

long long r = 1000000007;

long long  factorialMethod(long long k){
    long long  sum = 1;
    for (long long i = 1; i <= k; ++i)
    {
        sum = (sum * i)%r;
    }
    return sum%r;
}


int main(){
    long long n, m;
    cin >> n >> m;
    

    if(n == m-1){
        cout << (factorialMethod(n)*factorialMethod(m))%r << endl;
    }
    else if(n == m){
        cout << (2*factorialMethod(n)*factorialMethod(m))%r << endl;
    }
    else if(n == m+1){
        cout << (factorialMethod(n)*factorialMethod(m))%r << endl;
    }
    else{
        cout << "0" << endl;
    }

    return 0;
}