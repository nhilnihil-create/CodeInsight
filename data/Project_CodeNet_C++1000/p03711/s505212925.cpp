#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

int main()
{
    

    int xgroup,ygroup;
    int x,y;
    cin>>x>>y;
    switch(x)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
        xgroup=1;
        break;
        case 4:
        case 6:
        case 9:
        case 11:
        xgroup=2;
        break;
        case 2:
        xgroup=3;
        break;
    }

    switch(y)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
        ygroup=1;
        break;
        case 4:
        case 6:
        case 9:
        case 11:
        ygroup=2;
        break;
        case 2:
        ygroup=3;
        break;
    }
    if(xgroup==ygroup)
    cout<<"Yes";
    else
    cout<<"No";
}