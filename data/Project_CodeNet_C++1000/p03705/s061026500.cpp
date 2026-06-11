#include <bits/stdc++.h>
using namespace std;

int main(){
    long N, A, B;
    cin >> N >> A >> B;//nが個数、aが最小、bが最大

    if(A > B){
        cout << 0 << endl;
        return 0;
    }
    
    if(N == 1){
        if(A < B){
            cout << 0 << endl;
            return 0;
        }
        if(A == B){
            cout << 1 << endl;
            return 0;
        }
    }
    if(N == 2){
        long ansn2 = A + B;
        cout << ansn2 << endl;
        return 0;
    }

    if(N >= 3){
        long ansn3 = (A + (N-1) * B) - ((N-1) * A + B) + 1;
        cout << ansn3 << endl;
        return 0;
    }
}