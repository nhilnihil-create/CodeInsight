#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main(){
    int64_t N, A, B, digits_A, digits_B, ans = 10000000000;
    vector<int64_t> divisor;
    cin >> N;
    for(int i = 1; i <= sqrt(N); i++){
 
        if(N % i == 0) divisor.push_back(i);
 
    }
 
    for(int64_t x : divisor){
        A = x;
        digits_A = 0;
        digits_B = 0;
        B = N / A;
 
        while(A > 0){
            digits_A++;
            A /= 10;
        }
 
        while(B > 0){
            digits_B++;
            B /= 10;
        }
 
        if(digits_A >= digits_B){
            if(digits_A < ans) ans = digits_A;
        }
 
        if(digits_A <= digits_B){
            if(digits_B < ans) ans = digits_B;
        }
 
    }
 
    cout << ans << endl;
}