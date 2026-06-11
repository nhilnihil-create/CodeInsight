#include<iostream>

using namespace std;

long remain(long a, long b){
    if (a % b == 0){
        return b;
    }else
    {
        return a % b;
    }
}

int main(){
    long a, b, x, n;
    cin >> a >> b >> x;
   
    a += x - remain(a,x);
    b -= b % x;
    if (b >= a){
        n = (b - a)/x + 1;
    }else{
        n = 0;
    }
    
    cout << n << endl;
    return 0;
}