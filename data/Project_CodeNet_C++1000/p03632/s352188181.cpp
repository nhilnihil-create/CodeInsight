#include<iostream>
#include<vector>
using namespace std;

int main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    vector<bool> x(101),y(101);
    for(int i=a;i<b;i++){
        x[i]=true;
    }
    for(int i=c;i<d;i++){
        y[i]=true;
    }
    int cnt=0;
    for(int i=0;i<=100;i++){
        if(x[i]==true&&y[i]==true){cnt++;}
    }
    cout<<cnt<<endl;
    return 0;
}