#include<iostream>
#include <algorithm>
#include<string>
#include <numeric>
#include<math.h>
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    string a,b,c;
    cin>>a>>b>>c;
    string s = {a[0],b[0],c[0]};
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    cout<<s<<endl;
}
