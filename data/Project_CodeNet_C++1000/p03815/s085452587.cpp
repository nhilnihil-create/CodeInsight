#include<iostream>
#include<cmath>
using namespace std;
int main(){
    unsigned long long int x;
    cin>>x;
    if(x<=6){
        cout<<"1";
        return 0;
    }
    if(x<=11){
        cout<<"2";
        return 0;
    }
    unsigned long long int result=x/11;
    unsigned long long int rem=x%(result*11);
    if(rem<=6){
        result*=2;
        if(rem!=0)
        result++;
    }
    else
    {
        result*=2;
        result+=2;
    }
    cout<<result;
}