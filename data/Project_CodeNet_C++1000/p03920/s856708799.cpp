#include <iostream>
using namespace std;
typedef long long ll;
ll n,s=0,g,m;
int main(void){
    cin>>n;
    g=n+1;
    while(g-s>1){
        m=(g+s)/2;
        //cout<<s<<" "<<g<<endl;
        if(m*(m+1)/2>=n)g=m;
        else s=m;
    }
    //cout<<g<<endl;
    s=g*(g+1)/2-n;
    for(int i=1;i<=g;i++){
        if(i==s)continue;
        cout<<i<<endl;
    }
}
