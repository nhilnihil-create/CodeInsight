#include<iostream>

using namespace std;
typedef long long ll;

ll x,y;

signed main(){
    cin>>x>>y;

    if(x-y>1||y-x>1)cout<<"Alice"<<endl;
    else cout<<"Brown"<<endl;

    return 0;
}