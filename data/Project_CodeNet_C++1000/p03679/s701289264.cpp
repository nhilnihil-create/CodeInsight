#include<bits/stdc++.h>
using namespace std;

int main(){

    int x,a,b;
    cin>>x>>a>>b;

    if(b-a>=x+1) cout<<"dangerous"<<endl;
    else if(b-a>0) cout<<"safe"<<endl;
    else cout<<"delicious"<<endl;








    return 0;
}