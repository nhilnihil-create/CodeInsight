#include <iostream>
using namespace std;

int main(){
    string s;
    cin >> s;
    int count;
    count = s.size();
    string inter;
    inter = to_string(count - 2);
    cout << s[0]+inter+s[count -1] << endl;
}