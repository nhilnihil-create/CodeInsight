#include<iostream>
using namespace std;

int main(){
    string s;
    cin >> s;
    int max=s.size();
    cout << s.at(0);
    cout << (max-2);
    cout << s.at(max-1) << endl;
}