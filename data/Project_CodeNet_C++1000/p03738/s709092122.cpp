#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main()
{
    string x,y,p,q;
    int a,b;
    cin >> x;
    cin >> y;

    if(x.length()>y.length()) {
        cout << "GREATER" << endl;
        return 0;
    }
    else if(x.length()<y.length()) {
        cout << "LESS" << endl;
        return 0;
    }
    else
    {
        for (int i = 0; i < x.length(); i++)
        {
            p = x.at(i);
            a = atoi(p.c_str());
            q = y.at(i);
            b = atoi(q.c_str());
            if(a>b) {
                cout << "GREATER" << endl;
                return 0;
            }
            else if(a<b) {
                cout << "LESS" << endl;
                return 0;
            }
        }
        cout << "EQUAL" << endl;
    }
    return 0;
}