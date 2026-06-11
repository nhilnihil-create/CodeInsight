#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin >> str;
    
    for(int i=0; i<str.size(); i++){
        if(count(str.begin(), str.end(), str[i])%2 != 0){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}