#include <iostream>
#include <string>
using namespace std;
int main(int argc, char** argv){
    string s;
    cin >> s;
    int n = s.length();
    cout << s[0] << n-2 << s[n-1] << "\n";
    return 0;
}
