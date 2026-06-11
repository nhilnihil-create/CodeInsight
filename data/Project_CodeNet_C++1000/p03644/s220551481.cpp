#include <bits/stdc++.h>
using namespace std;

int main(){

    int N;
    cin >> N;

    int count = 0;
    int product = 2;
    while(true){
        if(N < product)  break;

        product *= 2;
        ++count;
    }

    cout << product/2 << endl;

    return 0;
}
