#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s;
    string t ="CODEFESTIVAL2016";

    int res = 0;

    cin >> s;

    for(int i=0;i<16;i++)
    {
    	if(s[i]!=t[i])
    	{
    		res++;
    	}
    }

    cout << res << '\n';
    
    return 0;
}