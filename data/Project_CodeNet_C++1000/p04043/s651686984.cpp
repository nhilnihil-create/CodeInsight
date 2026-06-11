#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <string>
using namespace std;

int max_abc(int a, int b, int c)
{
    int m = max(max(a, b), c);
    return m;
}

int main(void)
{
    int a,b,c;
    cin >>a >>b >>c;

    if(a*b*c==5*7*5)
    {
        cout <<"YES";
    }else{
        cout <<"NO";
    }
}