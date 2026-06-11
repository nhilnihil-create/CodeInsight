#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int a, f, s;
    f = s = 0;
    for(int i = 0; i < 3; ++i){
        cin >> a;
        if(a == 5){
            ++f;
        }
        else if(a == 7){
            ++s;
        }
    }
    
    if(f == 2 && s == 1){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}
