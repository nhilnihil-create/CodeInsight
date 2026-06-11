#include<iostream>
#include <algorithm>
#include<string>
#include <numeric>
#include<math.h>
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int x[3];
    cin>>x[0]>>x[1]>>x[2];
    sort(x,x+3);
    cout<<x[0]+x[1]<<endl;
}
