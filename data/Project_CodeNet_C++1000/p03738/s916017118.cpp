#include<iostream>
using namespace std;
int main(){
    string s,p;
    cin>>s;
    cin>>p;
    if(s.size()>p.size()){
        cout<<"GREATER"<<endl;
    }
    else
    if(s.size()<p.size()){
        cout<<"LESS"<<endl;
    }
    else
    {
        int greater=-1;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>p[i]){
                greater=1;
                break;
            }
            else
            if(s[i]<p[i]){
                greater=0;
                break;
            }
        }
        if(greater==-1){
            cout<<"EQUAL"<<endl;
        }
        else
        if(greater==1){
            cout<<"GREATER"<<endl;
        }
        else{
            cout<<"LESS"<<endl;
        }
    }
}