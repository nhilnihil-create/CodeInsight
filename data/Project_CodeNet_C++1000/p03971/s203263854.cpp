#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, A, B;
    cin >> N >> A >> B;
    string S;
    cin >> S;

    int a = 0;
    int b = 0;
    
    for(int i=0; i<N; i++) {
        switch(S.at(i)) {
            case 'a':
                if(a+b < A+B) {
                    cout << "Yes" << endl;
                    a++;
                } else {
                    cout << "No" << endl;
                }
            break;
            case 'b':
                if(a+b < A+B && b < B) {
                    cout << "Yes" << endl;
                    b++;
                } else {
                    cout << "No" << endl; 
                }
            break;
            case 'c':
                cout << "No" << endl;
            break;
        }
    }

}