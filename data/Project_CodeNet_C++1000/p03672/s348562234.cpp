#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cin >> s;
    int end = s.size() % 2 == 0 ? s.size() - 2 : (s.size() - 1);
    int half = end / 2;
    int ans = 0;
    while (end > 0){
//        cout << "before : " << s.substr(0, half) << endl;
//        cout << "after : " << s.substr(half, half) << endl;
        if(s.substr(0, half) == s.substr(half, half)) break;
        end -= 2;
        half = end / 2;
    }
    ans = end;
    cout << ans << endl;
}