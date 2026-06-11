#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
int iIn1,iIn2,iIn3;

int main()
{
        cin>>iIn1>>iIn2>>iIn3;
        if(iIn2-iIn1==iIn3-iIn2)
                cout<<"YES"<<endl;
        else
                cout<<"NO"<<endl;
        return 0;
}
