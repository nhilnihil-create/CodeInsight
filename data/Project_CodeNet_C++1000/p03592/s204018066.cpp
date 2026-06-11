#include<iostream>
using namespace std;

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i*(m-j)+j*(n-i)==k){
                cout<<"Yes"<<endl;
                return 0;
            }
        }
    }
    cout<<"No"<<endl;
}