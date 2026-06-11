#include <bits/stdc++.h>
#include <string>
#include <algorithm>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <float.h>
#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
    int N,rN,temp;

    cin>>N;
    temp=N;

    int x,y,z;
    x=temp/100;
    temp%=100;
    y=temp/10;
    z=temp%10;

    rN=z*100+y*10+x;

    if(N==rN){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }

    return 0;
}
