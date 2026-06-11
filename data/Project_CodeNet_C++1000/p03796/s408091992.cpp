#include<iostream>
#include<cmath>
using namespace std;
int main(){
    long long a;
    a = pow(10,9);
    long long b;
    b = 7;
    long long big;
    big = a+b;
    int n;
    cin >> n;
    long long pow=1;
    for(int i=1; i<=n; i++){
        pow = pow*i%big;
    }
    cout << pow << endl;
}

