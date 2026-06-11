#include<bits/stdc++.h>
using namespace std;
int main(){
    long long A, B, X;
    cin >> A >> B >> X;
    if(A % X == 0){
        cout << B / X - A / X + 1 << endl;
    }
    else{
        cout << B / X - A / X << endl;
    }
    return 0;
}