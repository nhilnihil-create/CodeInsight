#include <bits/stdc++.h>
using namespace std;

int main()
{
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	string a,b;
	cin >> a >> b;
	if(a.length() > b.length())
    {
        cout << "GREATER";
        return 0;
    }
    else if(b.length() > a. length())
    {
        cout << "LESS";
        return 0;
    }
    int x,y;
    for(int i = 0; i < a. length(); i++)
    {
        x = a[i] - '0';
        y = b[i] - '0';
        if(x > y)
        {
            cout << "GREATER";
            //cout << x << y;
            return 0;
        }
        else if(y > x)
        {
            cout << "LESS";
            return 0;
        }
    }
    cout << "EQUAL";

}
