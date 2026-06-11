#include <iostream>
#include <vector>
using namespace std;
int main(void){
    string s,t = "CODEFESTIVAL2016";
    cin >> s;
    int ans = 0;
    for(int i=0; i<16; i++){
        if(s[i] != t[i]){
            ans += 1;
        }
    }
    cout << ans << endl;
}