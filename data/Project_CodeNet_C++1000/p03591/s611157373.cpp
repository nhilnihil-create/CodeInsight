#include <iostream>
using namespace std;

int main(){
    string s;cin>>s;
    bool judge = false;
    if (s.size() < 4){
        cout << "No" << endl;
        return 0;
    }
    if (s[0] == 'Y' && s[1] == 'A' && s[2] == 'K' && s[3] == 'I'){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;

}