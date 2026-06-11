#include<bits/stdc++.h>
using namespace std;
main(){
long long i,j,k,l,m,n,p;
while(cin>>p>>n>>m){
if(m-n<=0)cout<<"delicious"<<endl;
else if(m-n<=p)cout<<"safe"<<endl;
else cout<<"dangerous"<<endl;
} return 0;
}
