#include<bits/stdc++.h>
using namespace std;

int main(){
    int A, B, C, D, sum1 = 0, sum2 = 0;
    cin >> A >> B >> C >> D;

    sum1 = A * B;
    sum2 = C * D;

    if(sum1 < sum2){
        cout << sum2 << endl;
    }
    else {
        cout << sum1 << endl;
    }

}