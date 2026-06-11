#include <bits/stdc++.h>
using namespace std;
 
int main(){
    long long X;
    cin >> X;

    long long cnt = 0;
    long long tmp = 0;
    for (long long i = 1; i < 1000000000; i++){
        cnt += i;
        tmp = i;
        if (cnt >= X){
            break;
        }
    }

    cout << tmp << endl;
}