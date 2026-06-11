#include<iostream>
#include<sstream>
using namespace std;
int main(){
    string s;
    getline(cin,s);
    cout << 'A' << s.at(8) << 'C' << endl;
    return 0;
}