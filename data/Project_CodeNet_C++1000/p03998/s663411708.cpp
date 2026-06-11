#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    deque<char> alist, blist, clist;
    string str;
    char chr;
    for (long long i=0; i<3; i++) {
        cin >> str;
        long long len=str.length();
        for (long long t=0; t<len; t++) {
            chr=str[t];
            if (i==0) {alist.push_back(chr);}   else if (i==1) {blist.push_back(chr);}  else if (i==2) {clist.push_back(chr);}}}
    chr=alist[0];
    while (true) {
        if (chr=='a' && alist.size()==0) {cout << "A"; break;} else if (chr=='b' && blist.size()==0) {cout << "B"; break;} else if (chr=='c' && clist.size()==0) {cout << "C"; break;}
        if (chr=='a') {chr=alist[0]; alist.pop_front();} else if (chr=='b') {chr=blist[0]; blist.pop_front();} else {chr=clist[0]; clist.pop_front();}}}