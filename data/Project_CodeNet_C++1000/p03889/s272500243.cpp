#include <iostream>
#include <map>
#include <string>
using namespace std;
int main(void){
    // Here your code !
    
    map<char,char> m;
    m['b'] = 'd';
    m['d'] = 'b';
    m['q'] = 'p';
    m['p'] = 'q';
    
    string str;
    cin >> str;
    
    for(int i = 0; i < str.size(); i++){
        if( str[str.size() - i - 1] != m[str[i]]){
            cout << "No" << endl;
            return 0;
        }
    }
    
    cout << "Yes" << endl;
    
}
