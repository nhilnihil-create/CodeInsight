#include<iostream>
#include <algorithm>
#include<string>
#include <numeric>
#include<math.h>
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int x,y;
    cin>>x>>y;
    if((x)%3==0)cout<<"Possible"<<endl;
    else if((y)%3==0)cout<<"Possible"<<endl;
    else if((x+y)%3==0)cout<<"Possible"<<endl;
    else cout<<"Impossible"<<endl;

}
