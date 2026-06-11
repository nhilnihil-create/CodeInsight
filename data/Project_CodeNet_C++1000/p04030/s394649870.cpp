#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    deque<char> list;
    string str, fin="";
    cin >> str;
    long long num=str.length(), sze;
    char chr;
    for (long long i=0; i<num; i++) {
        chr=str[i];
        sze=list.size();
        if (chr=='B' && sze>0) {list.pop_back();}
        else if (chr!='B') {list.push_back(chr);}}
    long long finsz=list.size();
    for (long long i=0; i<finsz; i++) {
        chr=list[i];
        fin+=chr;}
    cout << fin;}