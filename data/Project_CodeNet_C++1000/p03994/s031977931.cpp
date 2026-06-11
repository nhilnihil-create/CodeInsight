#include<bits/stdc++.h>
using namespace std;

int main(void) {
    string s;
    cin >> s;
    long k;
    cin >> k;

    for(long i=0; i<s.size(); i++) {
        long c = (26 - (s[i]-'a')) % 26;
        if(c <= k)
            s[i] = 'a', k -= c;
    }
    {
        long i = s.size()-1;
        s[i] = ((s[i]-'a'+k)%26) + 'a';
    }
    cout << s << endl;
}
