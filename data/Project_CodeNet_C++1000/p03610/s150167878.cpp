#include <bits/stdc++.h>
using namespace std;
using ll = long long; // ll は long long　と同じとする。(int64_t)
int main(){
    string s;
    cin >> s;
    string a;
    for(int i = 0; i < s.size(); i+=2){
        a+=s.at(i);
    }
    cout << a << endl;
}