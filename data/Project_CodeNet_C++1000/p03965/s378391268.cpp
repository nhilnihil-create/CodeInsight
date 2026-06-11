#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;

    int count = 0;
    for(int i=0; i<s.length(); i++){
        if(s[i] == 'g') count += 1;
        if(s[i] == 'p') count -= 1;
    }
    cout << count / 2 << endl;
    return 0;
}