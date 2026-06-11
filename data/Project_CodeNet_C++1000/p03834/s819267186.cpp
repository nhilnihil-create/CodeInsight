#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define MIN(a,b) ((a)>(b)? (b): (a))
#define MAX(a,b) ((a)<(b)? (b): (a))
const long long INF = 1LL << 60;
typedef unsigned long long ll;
const long long MOD = 1000000000 + 7;

string replaceStr(string &replacedStr, string from,string to){
    unsigned int pos = replacedStr.find(from);
    int toLen = to.length();

    if(from.empty()){
        return replacedStr;
    }

    while((pos = replacedStr.find(from,pos)) <= replacedStr.size()){
        replacedStr.replace(pos,from.length(),to);
        pos += toLen;
    }
    return replacedStr;
}


int main(){
    string s;
    cin >> s;
    replaceStr(s,","," ");
    cout << s << endl;

    return 0;
}