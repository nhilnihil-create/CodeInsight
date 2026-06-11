#include<bits/stdc++.h>

#define ll   long long int
#define PI 3.14159265358979
#define zig ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;


int main()
{
    zig
    string a, b, c;
    char turn='a';
    cin>>a>>b>>c;
    while(1)
    {
        if(turn=='a')
        {
            if(a.empty())
            {
                cout<<'A';
                break;
            }
            turn=a[0];
            a.erase(0, 1);
        }
        else if(turn=='b')
        {
            if(b.empty())
            {
                cout<<'B';
                break;
            }
            turn=b[0];
            b.erase(0, 1);
        }
        else
        {
            if(c.empty())
            {
                cout<<'C';
                break;
            }
            turn=c[0];
            c.erase(0, 1);
        }
    }
    return 0;
}
