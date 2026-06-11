#include<iostream>
#include<bits/stdc++.h>
#include<iomanip>
#include<math.h>
#include<vector>
#include<cctype>
#include<string>
#include<set>
#include<map>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
std::string line;
typedef long long ll;

int main(){

   int a,b;
   cin >> a >>b;

   if((a+b)%3==0 | a%3==0 | b%3==0)cout << "Possible" << endl;
   else cout << "Impossible" << endl;

   return 0;
}