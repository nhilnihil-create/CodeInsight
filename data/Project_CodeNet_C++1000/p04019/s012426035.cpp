#include <iostream>
#include <set>

using namespace std;

int main() {
    string str;
    cin >> str;
    set<char> st;
    for(int i=0; i<str.size(); i++) {
        st.insert(str[i]);
    }
    if(st.size()%2) {
        cout << "No" << endl;
    } else {
        if((st.find('S')!=st.end()&&st.find('N')!=st.end()) || (st.find('E')!=st.end()&&st.find('W')!=st.end())) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
    
}