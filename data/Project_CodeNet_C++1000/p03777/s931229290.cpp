#include<iostream>
#include <algorithm>
#include<string>
#include <numeric>
#include<math.h>
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    char a,b;
    cin>>a>>b;
    if(a==b&&a=='H')cout<<a<<endl;
    if(a=='D'&&b=='H')cout<<a<<endl;
    if(a=='H'&&b=='D')cout<<b<<endl;
    if(a==b&&a=='D')cout<<"H"<<endl;
}
