#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string s;
    cin >> n >> s;
    stack<int> l;
    int r = 0;
    for(int i = 0;i < n;i++){
        if(s[i] == '(')l.push(1);
        if(s[i] == ')'){
            if(!l.empty())l.pop();
            else r++;
        }
    }
    for(int i = 0;i < r;i++){
        cout << '(';
    }
    cout << s;
    for(int i = 0;i < l.size();i++){
        cout << ")";
    }
    cout << endl;
}
