#include <bits/stdc++.h>
using namespace std;
#define rep(i,c) for(int i=0;i<c;++i)
int main(){
int x,y,z;
cin >> x >> y >> z;
if(-y+z<=0) {
    cout << "delicious" << endl;
}else if(-y+z<=x){
    cout << "safe" << endl;
}else{
    cout << "dangerous" << endl;
}
return 0;
}