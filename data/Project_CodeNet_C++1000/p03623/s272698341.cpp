#include<iostream>
#include <algorithm>
#include<string>
#include <numeric>
#include<math.h>
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int x,a,b;
    cin>>x>>a>>b;
    if(abs(x-a)>abs(x-b))cout<<"B"<<endl;
    else cout<<"A"<<endl;

}
