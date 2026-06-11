#include <bits/stdc++.h>
using namespace std;
 
int main(){
    string S;
    cin >> S;

    string L = "CODEFESTIVAL2016";
    int N = S.length();
    int count = 0;

    for (int i = 0; i < N; i++){
        if (S[i] != L[i]){
            count++;
        }
    }
    cout << count << endl;
}