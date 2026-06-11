#include<bits/stdc++.h>
using namespace std;
string s;
bool ok(int x) {
    int p = x/2;
    for(int i = 0, j = p + 1; i < p; i++, j++) {
        if(s[i] != s[j]) return false;
    }
    return true;
}
int main()
{
    int ln;
    cin>>s;
    ln = s.size();
    for(int i = ln-2; i >= 2; i -= 2) {
        if(ok(i-1)) {
            cout<<i<<endl;
            break;
        }
    }
}
