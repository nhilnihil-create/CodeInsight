#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#define ll long long int

using namespace std;

int a[5];

int main()
{
    ///freopen("INA.txt","r",stdin);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

    cin>> a[1] >> a[2] >> a[3];
    int f=0,s=0;

    if(a[1]==5){ f++; }
    if(a[2]==5){ f++; }
    if(a[3]==5){ f++; }

    if(a[1]==7){ s++; }
    if(a[2]==7){ s++; }
    if(a[3]==7){ s++; }

    if(f==2 && s==1){ cout<< "YES" << endl;}
    else{ cout<< "NO" << endl; }

    return 0;
}

