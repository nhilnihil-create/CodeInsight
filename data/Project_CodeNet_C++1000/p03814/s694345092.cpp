#include <iostream>
#include <string>
using namespace std;
int main(){
    string s; cin >> s;
    int first = 10000000, last = 0;
    for(int i = 0; i<s.size(); i++){
        if(s[i] == 'A') first = min(first, i);
    }
    for(int i = s.size()-1; 0<i; i--){
        if(s[i] == 'Z') last = max(last,i);
    }
    cout << last+1-first << endl;
    return 0;
}