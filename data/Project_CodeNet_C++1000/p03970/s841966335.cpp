#include <iostream>

using namespace std;

int main(){
    string s;
    cin >> s;
    string str = "CODEFESTIVAL2016";
    int result = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == str[i]){
            continue;
        }
        else{
            result++;
        }
    }
    cout << result << endl;
}