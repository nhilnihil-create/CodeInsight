#include <bits/stdc++.h>

using namespace std;

int main() {
    long long a , b ;
    char c ; 
    scanf("%lld %c %lld", &a , &c , &b);
    if(c == '+'){
        cout << a + b << endl;
        return 0;
    }
    cout << (a - b) << endl;
}