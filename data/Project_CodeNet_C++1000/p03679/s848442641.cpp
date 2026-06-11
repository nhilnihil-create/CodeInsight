#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int x,a,b;
    cin>>x>>a>>b;
    if(b<=a)cout<<"delicious"<<endl;
    else if(b>a+x) cout<<"dangerous"<<endl;
    else cout<<"safe"<<endl;
    return 0;
}
