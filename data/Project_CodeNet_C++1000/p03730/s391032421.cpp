#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
using namespace std;

int main() {
    //input
    int A,B,C;cin >> A >> B >> C;
    int p;
    p = 0;
    A = A % B;


    //compute
    for(int i = 1; i < B;i++){
        if(( A * i ) % B == C ){
            p = 1;
            break;
        }
    }

    //output
    if(p == 1 ){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

}