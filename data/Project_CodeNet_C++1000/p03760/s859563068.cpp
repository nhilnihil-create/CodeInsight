#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

int main() {    
    string o,e;
    cin >> o >> e;
    for(int i = 0; i < o.size(); i++) {
        cout << o[i];
        if(i < e.size()) cout << e[i];
    }
    cout << endl;
    return 0;
}
