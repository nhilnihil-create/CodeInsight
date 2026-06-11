#include<iostream>
#include<string>
#include<stack>

using namespace std;

string str;
stack<char> stk;

int main() {
    cin >> str;
    for(auto s : str) {
        switch(s) {
            case '0':
            case '1':
                stk.push(s);
                break;
            case 'B':
                if(!stk.empty())
                    stk.pop();
        }
    }
    string ans;
    while(!stk.empty()) {
        ans = stk.top() + ans;
        stk.pop();
    }
    cout << ans << endl;
    return 0;
}