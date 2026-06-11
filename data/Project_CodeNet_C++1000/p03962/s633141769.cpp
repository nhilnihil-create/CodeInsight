#include <bits/stdc++.h>
using namespace std;

int main(){
    
    set<int> penki;
    for (int i = 0; i < 3; i++) {
        int buf;
        cin >> buf;
        penki.insert(buf);
    }
    
    cout << penki.size() << endl;
}
