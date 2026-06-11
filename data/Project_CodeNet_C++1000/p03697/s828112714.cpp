#include <iostream>

using namespace std;

int main(){
    int A, B;
    cin >> A >> B;

    int sum = A + B;

    if(sum < 10){
        cout << sum << endl;
    } else{
        cout << "error" << endl;
    }
    return 0;
}