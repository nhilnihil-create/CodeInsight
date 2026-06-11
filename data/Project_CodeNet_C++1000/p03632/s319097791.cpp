#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793


   
int main(){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    int ans;
    if(a<=c){
      if(b<=c)ans=0;
      else if(b<=d)ans=b-c;
      else if(b>d)ans=d-c;
    }
    else if(a>c){
      if(d<=a)ans=0;
      else if(d<=b)ans=d-a;
      else if(d>b)ans=b-a;
    }
    cout << ans << endl;
  }
