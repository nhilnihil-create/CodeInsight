#include <bits/stdc++.h>
using namespace std;

int main(){
    string o,e;
    cin >> o >> e;
    for(int i=0; i<e.length(); i++){
        cout << o.at(i) << e.at(i);
    }
    if(o.length()!=e.length()) cout << o.at(o.size()-1);
    cout << endl;
}