#include<bits/stdc++.h>

#define ll   long long int
#define PI 3.14159265358979
#define zig ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;


char c_turn(string& a)
{
    if(a.empty())
    {
        return '1';
    }
    char turn=a[0];
    a.erase(0, 1);
    return turn;

}

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
            turn=c_turn(a);
            if(turn=='1')
            {
                cout<<'A';
                break;
            }
        }
        else if(turn=='b')
        {
            turn=c_turn(b);
            if(turn=='1')
            {
                cout<<'B';
                break;
            }
        }
        else
        {
            turn=c_turn(c);
            if(turn=='1')
            {
                cout<<'C';
                break;
            }
        }
    }
    return 0;
}
