#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793

int main(){
 char a,b;
 cin >> a >> b;
 char ans;
 if(a=='H' && b=='H')ans='H';
 if(a=='H' && b=='D')ans='D';
 if(a=='D' && b=='H')ans='D';
 if(a=='D' && b=='D')ans='H';
 cout << ans << endl;
}

