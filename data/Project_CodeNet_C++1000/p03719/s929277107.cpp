#include <iostream>
#include <algorithm>
using namespace std;

int main(){
 int a , b ,c;
 cin >> a >> b >> c;
 int k = max({a , b , c});
 int l = min({a , b , c});
 if(a == l && b == k)cout << "Yes" << endl;
 else cout << "No" << endl;
}
