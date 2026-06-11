#include<iostream>
using namespace std;

long long MOD = 5;

long long extGCD(long long a, long long b, long long *px, long long *py){
    if(b == 0){
        *px = 1;
        *py = 0;
        return a;
    }
    long long d = extGCD(b, a%b, py, px);
    *py -= a/b * (*px);
    return d;
}

long long modinv(long long a, long long mod){
    long long x, y;
    extGCD(a, mod, &x, &y);
    x %= mod;
    if(x < 0) x += mod;
    return x;
}

int main(){
    //input
    long long N,X;
    cin >> N >> X;

    //output
    long long x, y;
    cout << 3*(N/extGCD(N,X,&x,&y)-1)*extGCD(N,X,&x,&y) << endl;
    system("pause");
    return 0;
}