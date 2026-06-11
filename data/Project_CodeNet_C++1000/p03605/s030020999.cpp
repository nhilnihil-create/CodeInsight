#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    if (N % 10 == 9){
        cout << "Yes" << endl;
    }
    else if (90<=N && N<=99){
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}