#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ALL(obj) (obj).begin(), (obj).end() 
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)

int main(){
    int n,i=0,u=0,r=0;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    sort(ALL(a), greater<int>());
  
    while((i+1<n) && ( i < a[i+1] && a[i] > i+1) && a[i+1] != i+1) i++;
    while(((i+r+1) < n) &&  i < a[i+r+1] ) r++;
    while(i+u+1 < a[i]) u++;
   
    if(r%2==0 && u%2==0) cout << "Second" << endl;
  	else  cout << "First" << endl;
    return 0;
}