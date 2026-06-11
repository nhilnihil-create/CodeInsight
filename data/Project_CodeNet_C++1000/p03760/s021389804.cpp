#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    string str1,str2;
    cin>>str1>>str2;
    for(int i=0;i<str1.size();i++){
        if(i!=str1.size()-1)cout<<str1[i]<<str2[i];
        else{
            if(str1.size()!=str2.size())cout<<str1[i]<<endl;
            else cout<<str1[i]<<str2[i]<<endl;
        }
    }
    return 0;
}