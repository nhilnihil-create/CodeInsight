#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    int n,a,b;
    cin>>n>>a>>b;
    string s;
    cin>>s;
    int oa=0,ob=0;
    for(int i=0;i<n;i++){
        if(s[i]=='c')cout<<"No"<<endl;
        else if(s[i]=='a'){
            if(oa+ob<a+b){
                cout<<"Yes"<<endl;
                oa++;
            }else{cout<<"No"<<endl;}
        }else if(s[i]=='b'){
            if(oa+ob<a+b&&ob<b){
                cout<<"Yes"<<endl;
                ob++;
            }else{cout<<"No"<<endl;}
        }
    }
    return 0;
}