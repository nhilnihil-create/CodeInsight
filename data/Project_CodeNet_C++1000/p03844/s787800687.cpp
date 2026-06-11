//2020-08-20, Thu

#include<iostream>
using namespace std;

int main(){
    int a, b;
    string s;
    cin >> a >> s >> b;
    if (s == "+") cout << (a + b) << endl;
    else cout << (a - b) << endl;

    return 0;
}