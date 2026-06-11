#include<iostream>
#include <algorithm>
#include<string>
#include <numeric>
#include<math.h>
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int a,b;
    cin >>a>>b;
    string ans="";
    if(a>b)ans="Alice";
    else if(a<b)ans="Bob";
    if(a==1&&b!=1)ans="Alice";
    if(a!=1&&b==1)ans="Bob";

    if(a==b)ans="Draw";


    cout<<ans<<endl;
}
