#include <iostream>
using namespace std;
int main(void){

    int A,B,C,D;
    cin >> A >> B >> C >> D;
    
    const int first = max(A,C);
    const int last = min(B,D);
    
    cout << max(0,last-first);
}