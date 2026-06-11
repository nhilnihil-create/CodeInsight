#include<iostream>
#include<string>

using namespace std;

int main() {
    string s;
    cin >> s;
    
    int size = s.size();
    size = (size - 2);
    char f = s.front();
    char b = s.back();
    cout << f << size << b;
}