#include <iostream>
using namespace std;

typedef long long ll;

ll x,y;

int main(void){
    cin>>x>>y;
    ll z=max(x, y)-min(x, y);
    if(z<2){
        cout<<"Brown"<<endl;
    }else{
        cout<<"Alice"<<endl;
    }
    return 0;
}
