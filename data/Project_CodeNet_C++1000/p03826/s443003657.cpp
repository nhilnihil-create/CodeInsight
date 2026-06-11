#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int A, B, C, D;
    
    cin >> A >> B >> C >> D;
    
    int AB = A * B;
    
    int CD = C * D;
    
    if ( AB < CD )
    cout << CD << endl;
    
    else if ( AB > CD )
    cout << AB << endl;
    
    else 
    cout << AB << endl;
}
