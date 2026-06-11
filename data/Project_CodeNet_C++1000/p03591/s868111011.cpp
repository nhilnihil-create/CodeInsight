#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    string s;
    cin>>s;
    if(s.substr(0,4)=="YAKI")cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}