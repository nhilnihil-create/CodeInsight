#include <iostream>
using namespace std;
 
int main() {
    string s;
    int count=0;
    
    cin >> s;
    
    //cout << s.size() << endl;
    
    cout << s[0] << s.size()-2 << s[s.size()-1] << endl;
    
    return 0;
}