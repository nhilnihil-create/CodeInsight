#include <iostream>

using namespace std;

int main() {
    long long int A, B, C;
    cin >> A >> B >> C;

    if(A==B && B==C) {
        if(A%2) {
            cout << 0 << endl;
        } else {
            cout << -1 << endl;
        }
    } else {
        int cnt=0;
        while(A%2==0 && B%2==0 && C%2==0) {
            long long int tmpA=(B+C)/2, tmpB=(A+C)/2;
            C = (A+B)/2;
            A = tmpA;
            B = tmpB;
            cnt++;
        }
        cout << cnt << endl;
    }


    return 0;
    
}