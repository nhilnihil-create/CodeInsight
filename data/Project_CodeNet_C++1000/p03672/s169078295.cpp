#include <iostream>
#include <string>
using namespace std;
int main(){
    string s; cin >> s;
    s = s.substr(0,s.size()-1);
    while(1){
        int n = s.size();
        s = s.substr(0,n-1);
        if(s.size()%2 != 0) continue;
        if(s.substr(0,n/2) == s.substr(n/2)){
            cout << n-1 << endl;
            break;
        }
    }
    return 0;
}