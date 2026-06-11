#include<bits/stdc++.h>
using namespace std;
int main(){
    string a;
    cin>>a;
    for(int i=0;i<a.size();i++){
        if(a.size()<4){
            cout<<"No"<<endl;
            return 0;
        }
        else if(a[0]=='Y'&&a[1]=='A'&&a[2]=='K'&&a[3]=='I'){
            cout<<"Yes"<<endl;
            return 0;
        }
        else{
            cout<<"No"<<endl;
            return 0;
        }
    }
}