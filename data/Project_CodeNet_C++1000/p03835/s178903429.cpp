#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;

int main() {
    int K,S,X,Y,Z;
    cin >> K >> S;
    int total ;
    int count_ =  0;
    for(X=0;X<=K;X++){
        for(Y=0;Y<=K;Y++){
            Z = S -(X + Y);
            if(0<= Z && Z <= K){
                count_ = count_ + 1;
            }
        }
    }
    cout << count_ << endl;
}  
