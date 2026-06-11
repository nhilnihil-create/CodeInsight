#include <iostream>
using namespace std;

int main(){
    int N, a, b;
    cin >> N;
    a = N/100;
    b = N%10;
    cin >> a >> b;
    if (a == b){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}