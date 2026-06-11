#include <iostream>
#include <string>
using namespace std;

int main(void){
    string S;
    cin >> S;
    int n;
    n = S.length();
    cout << S[0] << n-2 << S[n-1] << endl;
    return 0;
}