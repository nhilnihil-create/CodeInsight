#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cin >> s;
    int size_num = s.length() - 2;
    cout << s[0] << size_num << s[size_num + 1] << endl;
    return 0;
}
