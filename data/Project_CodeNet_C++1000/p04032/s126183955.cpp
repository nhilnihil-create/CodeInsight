#include <iostream>
#include <vector>
using namespace std;
int main(void){
    int len;
    string s;
    cin >> s;
    len = s.length();
    for(int i=0;i<len-1;i++){
        if(s[i] == s[i+1]){
            cout << i+1 << " " << i+2 << endl;
            return 0;
        }
        if(i+2 < len && s[i] == s[i+2]){
            cout << i+1 << " " << i+3 << endl;
            return 0;
        }
    }
    puts("-1 -1");
}
