#include <iostream>
#include <string>
#include <map>
using namespace std;
int main(){
    string a,b,c;
    cin >> a >> b >> c;
    map<int,string> mp;
    mp[0] = a;
    mp[1] = b;
    mp[2] = c;
    int next = 0;
    while(1){
        if(mp[next].size() == 0){
            if(next == 0) puts("A");
            if(next == 1) puts("B");
            if(next == 2) puts("C");
            return 0;
        }
        char cc = mp[next].at(0);
        mp[next] = mp[next].substr(1);
        if(cc == 'a') next = 0;
        if(cc == 'b') next = 1;
        if(cc == 'c') next = 2;
    }
    return 0;
}