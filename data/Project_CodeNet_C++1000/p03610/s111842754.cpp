#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;
int abs(int x){
    if(x<0) return -x;
    else return x;
}
int main() {
    string s;
    cin>>s;
    for(int i=0;i<s.size();i+=2){
        cout<<s[i];
    }
    cout<<endl;

}