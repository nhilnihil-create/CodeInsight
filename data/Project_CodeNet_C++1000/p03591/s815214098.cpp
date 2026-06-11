#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

int main(){
    string s; cin >> s;
    for(int i = 0; i <4; i++){
        if((i == 0 && s[i] != 'Y' ) || (i == 1 && s[i] != 'A')
        || (i == 2 && s[i] != 'K') || (i == 3 && s[i] != 'I' )){
            cout << "No" << endl;
            return 0;
        }
    }   
    cout << "Yes" << endl;
    return 0;
}