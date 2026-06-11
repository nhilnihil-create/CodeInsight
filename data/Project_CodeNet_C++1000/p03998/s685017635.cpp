#include<bits/stdc++.h>

#define ll   long long int
#define PI 3.14159265358979
#define zig ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

string a, b, c;

void c_turn(string& q, char turn)
{
    if(q.empty())
    {
        cout<<(char)(turn-32);
        return;
    }
    else
    {
        turn=q[0];
        q.erase(0, 1);
        if(turn=='a')
            c_turn(a, turn);
        else if(turn=='b')
            c_turn(b, turn);
        else
            c_turn(c, turn);
    }
    return;

}

int main()
{
    zig
    char turn='a';
    cin>>a>>b>>c;
    c_turn(a, turn);
    return 0;
}
