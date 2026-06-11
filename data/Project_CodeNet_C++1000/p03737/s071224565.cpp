#include <iostream>
#include <string>
using namespace std;
int main(){
    string s,t,u; cin >> s >> t >> u;
    int diff = 'a' - 'A';
    cout << (char)(s[0]-diff) << (char)(t[0] - diff) << (char)(u[0] - diff) << endl;
    return 0;
}