#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    string s;
    cin >> s;

    int aind = 0;
    int zind = 0;

    for(int i = 0; i < s.size(); i++){
        if(s[i]=='A'){
            aind = i;
            break;
        }
    }

    for(int i = s.size()-1; i >= 0; i--){
        if(s[i]=='Z'){
            zind = i;
            break;
        }
    }

    cout << zind - aind + 1 << endl;
}