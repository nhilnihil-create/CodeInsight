#include <iostream>
#include <string>
using namespace std;

int main(){
    string a,b;
    cin >> a >> b;
    
    if(a == b){
        cout << "H" << endl;
    }else if(a != b){
        cout << "D" << endl;
    }
    
    return 0;
}