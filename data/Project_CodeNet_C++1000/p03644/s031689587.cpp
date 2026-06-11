#include <iostream>
using namespace std;

int main(void){
    int N;
    cin >> N;
    int a;
    if(64 <= N && N <= 100) {a = 64;} 
    else if(32 <= N && N < 64) {a = 32;}
    else if(16 <= N && N < 32) {a = 16;}
    else if(8 <= N && N < 16) {a = 8;}
    else if(4 <= N && N < 8) {a = 4;}
    else if(1 < N && N < 4) {a = 2;}
    else {a = 1;}
    
    cout << a<< endl;
    return 0;
}
