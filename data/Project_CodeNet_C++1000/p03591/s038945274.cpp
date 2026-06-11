#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <iomanip>

using namespace std;


int main(){
    string S; cin >> S;
    bool f = false;

    if (S.length() >= 4){
        if (S[0] == 'Y' && S[1] == 'A' && S[2] == 'K' && S[3] == 'I'){
            f = true;
        }
    }
    
    if (f == true) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}