#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    int x,a,b;
    cin>>x>>a>>b;
    if(b<=a) cout<<"delicious"<<endl;
    else if(b<=x+a) cout<<"safe"<<endl;
    else cout<<"dangerous"<<endl;
}