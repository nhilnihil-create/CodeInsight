#include<iostream>
#include<cstdio>

using namespace std;

int main(){
    long long n;
    cin>>n;
    long long t=n%50;
    long long c=n/50;
    c+=49;
    cout<<"50"<<endl;
    for(int i=1;i<=50;i++){
        if(i<=(50-t)){
            cout<<c-t<<" ";
        }
        else {
            cout<<c+50-t<<" ";
        }
    }
    return 0;
}
