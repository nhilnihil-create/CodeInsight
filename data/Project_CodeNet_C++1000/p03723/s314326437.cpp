#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    int a,b,c;
    cin>>a>>b>>c;
    long long cnt=0;
    while(a%2==0&&b%2==0&&c%2==0){
        if(a==b&&b==c){
            cout<<-1<<endl;
            return 0;
        }
        int ta=a,tb=b,tc=c;
        a=(tb+tc)/2;
        b=(tc+ta)/2;
        c=(ta+tb)/2;
        cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}