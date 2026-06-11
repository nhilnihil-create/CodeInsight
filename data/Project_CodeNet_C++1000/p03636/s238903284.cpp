#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int num = s.size() - 2;
    char head = s[0];
    char end = s[s.size() - 1];
    
    cout << head << num << end << endl;
    return 0;
}