#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    int h,w;
    cin>>h>>w;
    string s;
    for(int i=0;i<w+2;i++)cout<<"#";
    cout<<endl;
    for(int i=0;i<h;i++){
        cin>>s;
        cout<<"#"<<s<<"#"<<endl;
    }
        for(int i=0;i<w+2;i++)cout<<"#";
    cout<<endl;
    return 0;
}