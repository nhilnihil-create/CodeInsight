#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793


   
int main(){
 int x,y;
 cin >> x >> y;
 set<int> num;
  num.insert(4);
  num.insert(6);
  num.insert(9);
  num.insert(11);
  if(x==2 || y==2)cout << "No" << endl;
  else if(num.count(x)){
     if(num.count(y))cout << "Yes" << endl;
     else cout << "No" << endl;
  }
  else if(num.count(y))cout << "No" << endl;
  else cout << "Yes" << endl;
}
    