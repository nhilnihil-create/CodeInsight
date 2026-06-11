#include<iostream>
#include<cmath>
using namespace std;


int main(){
    int N,K;
    cin >> N >> K;

    cout << (int)round(K * pow(K-1,N-1)) << '\n';
}



