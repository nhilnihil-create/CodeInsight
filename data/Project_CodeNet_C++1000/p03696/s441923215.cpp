#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    stack<char> St;
    int frontnum = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '('){
            St.push(s[i]);
        }else if(!St.empty()){
            St.pop();
        }else{
            frontnum++;
        }
    }

    string ans = "";
    for(int i = 0; i < frontnum; i++) ans += '(';
    ans += s;
    for(int i = 0; i < St.size(); i++) ans += ')';
    cout << ans << endl;
    return 0;
}