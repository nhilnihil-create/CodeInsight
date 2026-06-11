#include <bits/stdc++.h>
#include <iostream>
#include<math.h>
#include<string>
#include<iomanip>
#include <numeric>
#include <limits>
using namespace std;
 
int main()
{
long long w,a,b,c; cin>>w>>a>>b;
if(b<a) swap(a,b);
if(b-(a+w)>0) cout<<b-(a+w);
else cout<<0;
return 0;
}