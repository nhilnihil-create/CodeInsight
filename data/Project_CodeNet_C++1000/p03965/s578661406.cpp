#include <iostream>
#include <vector>

using namespace std;

int main() {
    string str;
    cin >> str;
    
    int ans=0;
    for(int i=0; i<str.size(); i++) {
        if(i%2) {
            if(str[i]=='g') {
                ans++;
            }
        } else {
            if(str[i]=='p') {
                ans--;
            }
        }
    }
    
    cout << ans << endl;

    return 0;
    
}