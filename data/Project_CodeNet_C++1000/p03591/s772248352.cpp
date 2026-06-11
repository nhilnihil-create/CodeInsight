#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
    cin >> s;
    if(s.size()>=4 && s.at(0)=='Y' && s.at(1)=='A' && s.at(2)=='K' && s.at(3)=='I'){
      cout << "Yes" << endl;
    }
    else{
      cout << "No" << endl;
    }
}

