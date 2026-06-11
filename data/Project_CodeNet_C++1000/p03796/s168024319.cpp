// B Training Camp

#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;    
    cin >> N;
    long div = pow(10, 9) + 7;
    //long div = 1000000000 + 7;

    long num = 1;     // power
    long res = 0;

    for (int i = 0; i < N; i ++)    {
        num *= (i+1);
        res = num % div;
        num = res;
    }
    // res = num % div;        
    cout << num << endl;
}
