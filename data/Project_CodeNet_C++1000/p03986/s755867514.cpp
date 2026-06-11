#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    string x;
    cin >> x;
    stack<char> s;
    for(char c : x){
        if(s.empty())
            s.push(c);
        else if(s.top() == 'S' && c == 'T')
            s.pop();
        else
            s.push(c);
    }
    cout << s.size() << endl;
    return 0;
}