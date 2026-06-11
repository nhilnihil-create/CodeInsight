#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int a=-1,z;
    for(int i=0; i<s.size(); i++){
        if(a==-1 && s.at(i)=='A') a=i;
        if(s.at(i)=='Z') z=i;
    }
    cout << z-a+1 << endl;
}