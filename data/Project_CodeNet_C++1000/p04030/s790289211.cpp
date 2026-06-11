#include<iostream>
#include<string>
#include<list>

using namespace std;

int main(){
    string s;
    list<char> l;
    list<char>::iterator itr;
    cin >> s;
    int i;
    for (i=0; i<s.length(); i++){
        if (s[i] == '0'){
            l.push_back(s[i]);
        }else if (s[i] == '1'){
            l.push_back(s[i]);
        }else if (s[i] == 'B' && !l.empty()){
            l.pop_back();
        }
    }

    for (itr=l.begin(); itr!=l.end(); itr++){
        cout << *itr;
    }
    return 0;
}