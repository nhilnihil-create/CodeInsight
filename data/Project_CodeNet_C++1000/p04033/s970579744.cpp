#include <iostream>
#include <algorithm>

using namespace std;

int a, b;
int main()
{
    cin >> a >> b;
    if(a < 0)
    {
        if(b < 0)
        {
            if((b - a + 1) & 1) puts("Negative");
            else puts("Positive");
        }
        else if(b >= 0) puts("Zero");
    }
    else 
    {
        if(!a) puts("Zero");
        else puts("Positive");
    }

    return 0;
}