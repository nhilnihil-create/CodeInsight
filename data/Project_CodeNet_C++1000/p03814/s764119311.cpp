#include<bits/stdc++.h>
using namespace std;
static const int INFTY = (1 << 21);
int main(){
    string S;
    cin >> S;
    int a = INFTY, z = 0;
    for(int i = 0; i < S.size(); i++){
        if(S.at(i) == 'A'){
            a = min(a, i);
        }
        if(S.at(i) == 'Z'){
            z = max(z, i);
        }
    }
    cout << z - a + 1 << endl;
    return 0;
}