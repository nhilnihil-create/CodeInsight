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
    int A[7]={1,3,5,7,8,10,12},B[4]={4,6,9,11},C[1]={2},x,y;
    cin>>x>>y;

    int f=0;

    for(int i=0;i<7;i++){
        if(A[i]==x)f++;
        if(A[i]==y&&f==1){
            cout<<"Yes"<<endl;
            return 0;
        }
    }

    f=0;
    for(int i=0;i<4;i++){
        if(B[i]==x)f++;
        if(B[i]==y&&f==1){
            cout<<"Yes"<<endl;
            return 0;
        }
    }

    cout<<"No"<<endl;

    return 0;
}
