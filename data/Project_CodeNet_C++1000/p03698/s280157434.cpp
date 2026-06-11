#include <iostream>
#include <set>
#include <string>
using namespace std;
int main(){
    string s; cin >> s;
    set<char> st;
    for(char c:s){
        if(st.count(c) == 1){
            puts("no");
            return 0;
        }
        else{
            st.insert(c);
        }
    }
    puts("yes");
    return 0;
}