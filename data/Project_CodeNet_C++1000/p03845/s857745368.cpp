#include <bits/stdc++.h>
using namespace std;
long long n,t[150],m,p[150],x[150],y,sum,k;
int main(){
ios_base::sync_with_stdio(0);
cin.tie(0);cout.tie(0);
cin>>n;
for(int i=1;i<=n;i++){
    cin>>t[i];
}
cin>>m;
for(int i=1;i<=m;i++){
    cin>>p[i]>>x[i];
}
for(int j=1;j<=m;j++){

   for(int i=1;i<=n;i++){

    if(p[j]==i){


        sum+=x[j];
        k++;
    }
    else sum+=t[i];
   }
    if(k>0){
    cout<<sum<<endl;
    sum=0;}
}

return 0;

}
