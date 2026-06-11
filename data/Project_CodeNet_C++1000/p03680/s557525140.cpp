#include <bits/stdc++.h>
#include <iostream>
#include<math.h>
#include<cmath>
#include<string>
#include<iomanip>
#include <numeric>
#include <limits>
using namespace std;

int main()
{
int n,i=0,j=0; cin >> n; int a[n];
for(int x=0;x<n;x++) cin>>a[x];
for(int x = 0; x < n; x++)
{
  i++;
  if(a[j]==2) break;
  j= a[j]-1;
}
if(i<n) cout <<i<< endl;
else cout << -1 << endl;
return 0;
}
