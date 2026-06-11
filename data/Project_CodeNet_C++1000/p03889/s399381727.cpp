#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    string s, t;
    cin >> s;
    t = s;
    reverse(t.begin(), t.end());
    for(int i=0; i<(int)t.length(); i++){
        if(t[i]=='b') t[i]='d';
        else if(t[i]=='d') t[i]='b';
        else if(t[i]=='p') t[i]='q';
        else t[i]='p';
    }
    if(s==t){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}
