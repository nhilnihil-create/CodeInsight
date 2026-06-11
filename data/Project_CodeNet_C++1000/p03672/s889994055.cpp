#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cin >> s;
    int ans = s.length()-1;
    for(; ; ans--){
        if(ans % 2 != 0) continue;
        bool isok = true;
        for(int i = 0; i < ans/2; i++){
            if(s[i] != s[ans/2+i]) isok = false;
        }
        if(isok) break;
    }
    cout << ans << endl;
    return 0;
}