#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){

 int n;
 cin >> n;
 int a[n+1],total = 0;
 for(int i = 1; i <= n; i++){
  cin >> a[i];
  total += a[i]; 
 }	
 int m;
 cin >> m;
 int x,y;
 while(m--){
 cin >> x >> y;
 cout << total - a[x] + y << "\n";
 }
 return 0;	
}
