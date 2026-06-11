#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <set>
#include <iomanip>
#include <stdio.h>
#include <sstream>
#include <bits/stdc++.h>
using namespace std;
int main(void){
  int n;
  cin>>n;
  long long int ans=0;
  for(int i=1; i<=n; i++){
    ans+=i;
  }
  cout<<ans<<endl;
}