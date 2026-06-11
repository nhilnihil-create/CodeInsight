#include<bits/stdc++.h>
using namespace std;
int main(){
int x,ctr5=0,ctr7=0;
for(int i=0;i<3;i++){
    cin>>x;
    if(x==5){
        ctr5++;
    }
    else if(x==7){
        ctr7++;
    }
}
if(ctr5==2 && ctr7==1){
    cout<<"YES";
}
else{
    cout<<"NO";
}
}