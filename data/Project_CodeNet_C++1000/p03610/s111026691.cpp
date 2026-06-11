#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cin >> s;
    int N = s.length();
    string ans;
    for (int i=0; i < N; ++i){
        if (i % 2 == 0){
            ans += s[i];
        }
    }
    cout << ans << endl;
    return 0;
}
