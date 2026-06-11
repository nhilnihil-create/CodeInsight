#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793

int main(){
 VI a(3);
 rep(i,3)cin >> a.at(i);
 sort(a.begin(),a.end());
 int ans=a.at(0)+a.at(1);
 cout << ans << endl;
}