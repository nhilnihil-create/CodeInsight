#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{    
    string s;
    cin >> s;
    // s = "needed";
    int size_s = s.length();
    int sub_s, sub_e;
    sub_s = -1, sub_e = -1;
    // 1. 連続している文字があればok
    for(int i=0; i<size_s-1; ++i){
        if(s.substr(i, 1) == s.substr(i+1, 1)){
            sub_s = i+1;
            sub_e = i+2;
            break;
        } 
    }
    // 2. 1個間隔であればok
    for(int i=0; i<size_s-2; ++i){
        if(s.substr(i, 1) == s.substr(i+2, 1)){
            sub_s = i+1;
            sub_e = i+3;
            break;
        } 
    }

    // これらが無ければ十分不可能
    cout << sub_s << " " << sub_e << endl;
    return 0;
}