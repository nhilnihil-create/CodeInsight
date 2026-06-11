#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    string s;
    cin >> s;
    for(auto c : s){
        if(c == ','){
            cout << " ";
        } else {
            cout << c;
        }
    }
    cout << endl;
    return 0;
}