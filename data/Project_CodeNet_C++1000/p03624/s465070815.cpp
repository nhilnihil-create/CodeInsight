#include <iostream>
#include <string>
#include <set>
using namespace std;
int main(){
    string s; cin >> s;
    set<char> st;
    for(int i = 0; i < s.size(); i++){
        st.insert(s[i]);
    }
    for(int i = 0; i < 26; i++){
        char c = 'a';
        char now = (char)(c + i);
        if(st.count(now) == 0){
            cout << now << endl;
            return 0;
        }
    }
    cout << "None" << endl;
    return 0;
}