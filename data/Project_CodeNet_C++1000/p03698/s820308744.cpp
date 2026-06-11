#include<iostream>
#include<string>

using namespace std;

int main(){
    string s, _s, a = "yes";
    cin >> s;
    for(int i : s){
        if(_s.find(i) == string::npos){
            _s += i;
        }else{
            a = "no";
            break;
        }
    }
    cout << a << endl;
}