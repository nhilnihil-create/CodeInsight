#include <iostream>
#include <cstdio>
using namespace std;
 
int main(){
    string s;
    cin >> s;
    int n = s.size();
 
    int length;
    for(int i = 1; i < n/2; i++) {
        if(s.substr(0, n/2-i) == s.substr(n/2-i, n/2-i)){
            length = s.size() - 2*i;
            break;
        }
    }
 
    cout << length << endl;
 
    return 0;
}