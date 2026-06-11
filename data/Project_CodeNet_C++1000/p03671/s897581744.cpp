#include <iostream>
#include <bits/c++io.h>
#include <algorithm>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
 int a[3];
 cin>>a[0]>>a[1]>>a[2];
 sort(a,a+3);
 cout<<a[0]+a[1]<<endl;
}

