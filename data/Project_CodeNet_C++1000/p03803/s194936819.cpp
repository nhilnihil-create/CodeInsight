#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    int s1,s2;
    cin>>s1>>s2;
    if(s1==s2)cout<<"Draw"<<endl;
    else if((s1>s2&&s2!=1)||s1==1)cout<<"Alice"<<endl;
    else if((s2>s1&&s1!=1)||s2==1)cout<<"Bob"<<endl;    
    return 0;
}