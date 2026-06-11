#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    int x = 0;
    int ans = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == 'I') x++;
        else x--;

        if(ans < x) ans = x;
    }
    cout << ans << endl;
    return 0;
}