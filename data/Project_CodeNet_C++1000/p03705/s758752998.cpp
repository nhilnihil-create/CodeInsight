#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

int main() {
    long long int N, A, B;
    cin >> N >> A >> B;

    if(B-A<0){
        cout << 0 << endl;
    }
    else if(N==1){
        if(A==B){
            cout << 1 << endl;
        }
        else{
            cout << 0 << endl;
        }
    }
    else{
        cout << (N-2)*(B-A) + 1 << endl;
    }
}
