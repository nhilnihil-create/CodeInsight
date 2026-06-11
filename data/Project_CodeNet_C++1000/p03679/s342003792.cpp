#include <bits/stdc++.h>
using namespace std;
 
int main(){ 
    int x,a,b;
    cin>>x>>a>>b;
    if((a-b)>=0)cout<<"delicious";
    else if((a+x)<b)cout<<"dangerous";
    else cout<<"safe";
 
    return 0;
}