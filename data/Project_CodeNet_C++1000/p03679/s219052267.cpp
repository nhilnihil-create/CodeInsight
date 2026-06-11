#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793

int main(){
   int x,a,b;
   cin >> x >> a >> b;
   int d=b-a;
   if(d<=0)cout << "delicious" << endl;
   else if(d<=x)cout <<  "safe" << endl;
   else if(d>x)cout << "dangerous" <<endl;
}
