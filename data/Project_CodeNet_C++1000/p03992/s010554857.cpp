#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >>s;

    char l=s.at(11);

    for(int i=11; i>4; i--){
        s.at(i)=s.at(i-1);
    }

    s.at(4)=' ';

    cout << s << l << endl;
}