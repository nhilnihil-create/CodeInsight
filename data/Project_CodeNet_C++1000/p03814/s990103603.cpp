#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;

    cin >> s;

    int a = 0;
    int z = 0;

    for(int i=0;i<s.size();i++){
        if(s.at(i) == 'A'){
            a = i;
            break;
        }
    }

    for(int i=s.size() - 1;i>0;i--){
        if(s.at(i) == 'Z'){
            z = i;
            break;
        }
    }

    cout << z - a + 1 << endl;
}
