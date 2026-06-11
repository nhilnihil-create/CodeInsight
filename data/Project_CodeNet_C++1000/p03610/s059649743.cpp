#include <iostream>
#include <string>
using namespace std;

int main(void){
    string S;
    cin >> S;
    int n = S.length();
    string A;
    for(int i = 0; i < n; i+=2){
        A = A + S[i];
    }
    cout << A << endl;
    return 0;
}