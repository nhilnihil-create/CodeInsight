#include <bits/stdc++.h>
using namespace std;

int main() {
    int A,B;
    cin >> A >> B;

    if(A % 3 == 0){
        cout << "Possible";
        return 0;
    }else if(B % 3 == 0){
        cout << "Possible";
        return 0;
    }else if((A+B) % 3 == 0){
        cout << "Possible";
        return 0;
    }
    cout << "Impossible";
    return 0;
}