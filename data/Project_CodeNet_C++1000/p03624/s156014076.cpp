#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    char s[100010];
    cin >> s;
    bool v[26];
    
    for (int i = 0; i < 26; i++)
    {
        v[i]=false;
    }
    for (int i = 0; s[i]!= '\0'; i++)
    {
        v[s[i]-'a']=true;
    }
    
    for (int i = 0; i < 26; i++)
    {
        if(v[i]==false){
            char ans = 'a'+i;
            cout << ans << endl;
            return 0;
        }
    }
    cout << "None" << endl;
    return 0;
}