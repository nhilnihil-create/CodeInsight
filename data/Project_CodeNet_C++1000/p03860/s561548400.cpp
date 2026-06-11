#include <iostream>
using namespace std;
 
int main() {
  
    string s[3];
    cin >> s[0] >> s[1] >>s[2];
    
    for (int i=0 ; i<3 ; i++){
        cout << s[i].at(0) ;
    }
    
    cout <<endl;
}
