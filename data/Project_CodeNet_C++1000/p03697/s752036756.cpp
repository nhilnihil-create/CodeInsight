#include <bits/stdc++.h>
using namespace std;
#define rep(i,c) for(int i=0;i<c;++i)
int main(){
int x,y;
cin >> x>> y;
if(x+y>=10){
    cout << "error" << endl;
}else{
    cout << x+y << endl;
}
return 0;
}