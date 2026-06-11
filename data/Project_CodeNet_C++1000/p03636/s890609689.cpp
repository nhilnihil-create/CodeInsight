#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >>s;
    int cha_n = s.size()-2;
    char ini_c = s.at(0);
    char last_c = s.at(s.size()-1);
    cout << ini_c << cha_n << last_c << endl;
    
}