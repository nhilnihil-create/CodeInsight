#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793

int main(){
    int a,b,c;
    cin >> a >> b >> c;
    
    bool d=false;
    if(a==5 && b==5 && c==7)d=true;
    if(a==5 && c==5 && b==7)d=true;
    if(b==5 && c==5 && a==7)d=true;
    if(d)cout << "YES" << endl;
    else cout << "NO" << endl;

}