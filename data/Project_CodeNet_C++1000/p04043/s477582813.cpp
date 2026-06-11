#include<bits/stdc++.h>
using namespace std;

int main()
{
    int input;
    int seven = 0, five = 0;

    for(int i = 1; i <= 3; i++)
    {
        cin>> input;
        if(input == 7)
            seven++;

        else if(input == 5)
            five++;
    }

    if((five == 2)&&(seven == 1))
        cout<< "YES\n";

    else
        cout<< "NO\n";

    return 0;
}
