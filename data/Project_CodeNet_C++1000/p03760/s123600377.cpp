#include<iostream>
#include<vector>
using namespace std;
int main(){
    string o,e;
    cin>>o>>e;
    for(int i=0;i<o.size();i++)
    {
        cout<<o[i];
        if(i<e.size()){
            cout<<e[i];
        }
    }
    if(o.size()<e.size()){
        cout<<e[e.size()-1];
    }
}