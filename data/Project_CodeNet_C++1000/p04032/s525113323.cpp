#include <iostream>
#include <string>
using namespace std;

string str;
char ch;

int px,py;
int main()
{
    cin>>str; px=py=-1;
    int lg=str.length();
    if(str[0]==str[1])
    {
        cout<<1<<' '<<min(lg,3)<<'\n';
        return 0;
    }
    for(int i=2; i<lg; ++i)
        if(str[i-1]==str[i] || str[i-2]==str[i])
        {
            cout<<i-1<<' '<<i+1<<'\n';
            return 0;
        }
    cout<<-1<<' '<<-1<<'\n';
    return 0;
}


//https://atcoder.jp/contests/abc043/tasks/arc059_b?fbclid=IwAR1nkTmf1WOQJX8LHpmmf4YPIp15x5tlxq8pYPD7dTbjBD4Bz1CuFYpV3nU
