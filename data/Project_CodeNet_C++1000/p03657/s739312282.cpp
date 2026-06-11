#include <bits/stdc++.h>
using namespace std;
#define rep(i,c) for(int i=0;i<c;++i)
int main(){
int x,y;
cin >> x>> y;
if((x+y)%3==0||x%3==0||y%3==0){
    cout << "Possible" << endl;
}else{
    cout << "Impossible" << endl;
}
return 0;
}