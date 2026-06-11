#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793
 
   
int main(){
    int n;
    cin >> n;
    VI a(n);
    rep(i,n)cin >> a.at(i);
    int no=0;
    rep(i,n){
        if(a.at(i)%2==1)no++;
    }
    if(no%2==0)cout << "YES"  << endl;
    else cout << "NO" << endl;
} 
    