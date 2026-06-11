#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main()
{
    ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);


    string a, b;

    cin >> a >> b;

    if(a.size() > b.size())
    {
        cout << "GREATER";
    }

    else if(a.size() < b.size())
    {
        cout << "LESS";
    }

    else
    {
        bool big = 0;
        bool small = 0;

        for(int i=0; i<a.size(); i++)
        {
            if((a[i] - '0') < (b[i] - '0'))
            {
                small = 1;
                break;
            }

            else if((a[i] - '0') > (b[i] - '0'))
            {
                big = 1;
                break;
            }

            else if((a[i] - '0') == (b[i] - '0'))
            {
                continue;
            }
        }

        if(big == 0 && small == 0)
        {
            cout << "EQUAL";
        }

        else if(big)
        {
            cout << "GREATER";
        }

        else if(small)
        {
            cout << "LESS";
        }
    }





}







