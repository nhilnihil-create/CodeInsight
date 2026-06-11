#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

string s;
ll n;

int main()
{
    cin>>s>>n;
    for(ll i = 0; i + 1 < s.size(); i++)
    {
        if(n + s[i] < 'z' + 1LL) continue;
        if(s[i] == 'a') continue;
        n -= 'z' + 1LL - s[i];
        s[i] = 'a';
    }
    s[(ll)s.size() - 1] = (char)((n + s[(ll)s.size() - 1] - 'a') % 26 + 'a');
    cout<<s;
    return 0;
}
