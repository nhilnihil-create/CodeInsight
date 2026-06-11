#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i < (int)(n);i++)

int main(){
  int a[]={1,3,5,7,8,10,12};
  int b[]={4,6,9,11};
  int c[]={2};
  set<int> st1;
  set<int> st2;
  rep(i,7){
    st1.insert(a[i]);
  }
  rep(i,4){
    st2.insert(b[i]);
  }
  int x,y;
  cin >> x >> y;
  if ((st2.count(x) && st2.count(y)) || (st1.count(x) && st1.count(y))){
    cout << "Yes" << endl;
  }
  else cout << "No" << endl;

  
}