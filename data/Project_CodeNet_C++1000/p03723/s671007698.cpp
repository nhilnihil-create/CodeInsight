#include <bits/stdc++.h>
#include <queue>
using namespace std;

int main(){
    long long A, B, C;
    cin >> A >> B >> C;

    long long tmp_A = A;
    long long tmp_B = B;
    long long tmp_C = C;

    int counter = 0;
    while(true){
        if(tmp_A%2 == 1 || tmp_B%2 == 1 || tmp_C%2 == 1){
            break;
        }
        int _tmp_A = tmp_B/2 + tmp_C/2;
        int _tmp_B = tmp_A/2 + tmp_C/2;
        int _tmp_C = tmp_B/2 + tmp_A/2;

        tmp_A = _tmp_A;
        tmp_B = _tmp_B;
        tmp_C = _tmp_C;
        if(tmp_A == A && tmp_B == B && tmp_C == C){
            counter = -1;
            break;
        }


        counter += 1;
    }
    cout << counter << endl;
    return 0;
}