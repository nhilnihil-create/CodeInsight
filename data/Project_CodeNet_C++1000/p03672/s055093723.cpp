#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    string s;
    cin>>s;
    bool flag=false;
    int len=s.size();
    for(int i=1;i<s.size();i++){
        if((len-i)%2!=0)continue;
        else{
            string str1=s.substr(0,(len-i)/2);
            string str2=s.substr((len-i)/2,(len-i)/2);
            if(str1==str2){
                cout<<len-i<<endl;
                return 0;
            }
        }
    }
    return 0;
}