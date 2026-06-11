#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    string s;
    cin >> s;
    for(char c : s){
        if(c == ',') cout << ' ';
        else cout << c;
    }
    cout << endl;
}