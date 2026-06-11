#include<bits/stdc++.h>
using namespace std;
#define ll long long
const unsigned int M = 1000000007;
int data[105];
void sum(){
    data[0]=0,data[1]=1;
    for(int i=2;i<105;i++){
        data[i]=data[i-1]+i;
    }
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int a,b,c;
    while(cin>>a>>b>>c){
        if(c>=a&&c<=b)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}
