#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int N;
    cin >> N;
    vector<long long>T(N);
    for (int i = 0; i < N; i++) {
        cin >> T.at(i);
    }

    if (N == 1){
        cout << T.at(0) << endl;
        return 0;
    }

    long long gcd;
    long long lcm = T.at(0);

    long long X = T.at(0);
    long long Y = T.at(1);
    long long Z = X % Y;
    int count;

    for (int i = 1; i < N; i++) {
        count = 0;
        while (count == 0){
            if (Z == 0){
                gcd = Y;
                lcm = lcm / gcd * T.at(i);
                if (i != N-1){
                    X = T.at(i+1);
                    Y = lcm;
                    Z = X % Y;
                }
                count++;
            }
            else {
               X = Y; 
               Y = Z;
               Z = X % Y;
            } 
        }
    }
    cout << lcm << endl;
}



