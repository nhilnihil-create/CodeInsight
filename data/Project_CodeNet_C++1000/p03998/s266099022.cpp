#include<iostream>
#include<string>
#include<map>

using namespace std;


int main(){
    map<char, string> s;
    cin >> s['A'] >> s['B'] >> s['C'];
    char n = 'A', x;

    while(1){
        if (s[n].length() == 0){
            break;
        }else if (s[n][0] == 'a'){
            x = 'A';
        }else if (s[n][0] == 'b'){
            x = 'B';
        }else if (s[n][0] == 'c'){
            x = 'C';
        }
        s[n].erase(0, 1);
        n = x;
    }
    cout << n << endl;
    return 0;

}