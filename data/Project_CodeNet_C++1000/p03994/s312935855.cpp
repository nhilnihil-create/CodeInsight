#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s;
    int K;

    cin >> s;

    cin >> K;

    for(int i=0;i<s.length();i++)
    {
    	if(s[i]=='a')
    	{
    		continue;
    	}
    	int val = 26 - (s[i]-'a');
    	if(K >= val)
    	{
    		K-=val;
    		s[i] = 'a';
    	}
    }

    int val = s[s.length()-1] - 'a';
    val += K;
    val%=26;
    s[s.length()-1] = (char)(val+'a');

    cout << s << '\n';

    return 0;
}