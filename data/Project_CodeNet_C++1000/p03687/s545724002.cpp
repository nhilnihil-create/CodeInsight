#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cin >> s;

    int ans = 100100;
    for(char ch = 'a'; ch <= 'z'; ch++){
        string s1 = s;
        for(int count = 0; count <= s1.length(); count++){
            bool isok = true;
            for(int i = 0; i < s1.length()-count; i++){
                if(s1[i] != ch) isok = false;
            }
            if(isok){
                if(ans > count) ans = count;
            }
            for(int i = 0; i < s1.length(); i++){
                if(s1[i] == ch && i-1 >= 0) s1[i-1] = s1[i];
            }
        }
    }

    cout << ans << endl;
    return 0;
}