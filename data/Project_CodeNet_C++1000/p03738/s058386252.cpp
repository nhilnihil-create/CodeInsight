#include<iostream>
#include<string>

using namespace std;

int main(){
    int s1l, s2l;
    string s1, s2;

    cin >> s1 >> s2;
    s1l = s1.length();
    s2l = s2.length();

    if(s1l == s2l){
        if(s1 == s2){
            cout << "EQUAL" << endl;
        }else{
            cout << (s1 > s2 ? "GREATER" : "LESS") << endl;
        }
    }else{
        cout << (s1l > s2l ? "GREATER" : "LESS") << endl;
    }
}