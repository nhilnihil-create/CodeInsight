#include <iostream>
#include <string>
using namespace std;
int main(void){
    string s[3];
    cin >> s[0] >> s[1] >> s[2];
    string ans;
    for(int i=0;i<3;i++){
        ans.push_back(s[i][0] - 32);
    }
    cout << ans << endl;
}
