#include <iostream>
#include <string>
using namespace std;

int main(){
    string o,e;
    cin >> o;
    cin >> e;
    string ans = "";
    for(int i = 0; i < o.length()+e.length(); i++){
        if(i % 2 == 0 && i/2 < o.length()) ans += o[i/2];
        else if((i-1)/2 < e.length()) ans += e[(i-1)/2];
    }
    cout << ans << endl;
    return 0;
}