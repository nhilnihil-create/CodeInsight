#include<iostream>
#include<string>
#include<cmath>;
using namespace std;
string s;
int main(){
    cin>>s;
    int k=s.size();
    if(k%2!=0){
        cout<<"No";
        return 0;
    }
    for(int i=0;i<k/2;i++){
        int u=abs(s[i]-s[k-i-1]);
        if(u!=1&&u!=2){
            cout<<"No"; 
            return 0;
        }
    }
    cout<<"Yes";
    return 0;
}