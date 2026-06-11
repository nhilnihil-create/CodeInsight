#include <bits/stdc++.h>
using namespace std;
#define rep(i,c) for(int i=0;i<c;++i)
int main(){
int x,y,z;
cin >> x >> y >> z;
int d = min(min(x+y,y+z),x+z);
cout << d << endl;
return 0;
}