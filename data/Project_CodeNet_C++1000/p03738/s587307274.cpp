#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<map>
using namespace std;
/*
time:32m54s
WA:7
桁数が等しくないときは大小自明
桁数が等しいときは先頭から比較していく
文字列Aの先頭はA[0]であることに注意忘れがち!!!!!
これで7回間違えた!!!!!!!!!!
*/
int main() {
    string A, B;
    cin >> A >> B;
    long long na = A.size();
    long long nb = B.size();
    char a, b;
    if(na > nb)  {
        cout << "GREATER" << endl;
    }
    else if(na < nb) {
        cout << "LESS" << endl;
    }
    else if(A == B) {
        cout << "EQUAL" << endl;
    }
    else {
        for(int i = 0; i < na; i++){
            if(A[i] > B[i]) {
                cout << "GREATER" << endl;
                break;
            }
            else if(A[i] < B[i]) {
                cout << "LESS" << endl;
                break;
            }
            else continue;
        }
    }
    return 0;
}