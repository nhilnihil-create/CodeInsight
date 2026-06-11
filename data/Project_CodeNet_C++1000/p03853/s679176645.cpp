#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main()
{
    int h,w;
    char str[206][206];
    cin>>h>>w;
    getchar();
    for(int i=1; i<=h; i++)
    {
        for(int j=1; j<=w; j++)
        {
            str[i][j]=getchar();
        }
        getchar();
    }
    for(int i=1; i<=2*h; i++)
    {//cout<<2*h;
        for(int j=1; j<=w; j++)
        {
            cout<<str[int(floor((i+1.0)/2))][j];
        }
        cout<<endl;
    }
    return 0;
}
