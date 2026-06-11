#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int n; cin>>n;
    string s,t;
    cin>>s>>t;
    for(int i=n;i<=2*n;i++){
        if(s.substr(i-n)==t.substr(0,2*n-i)){
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<s.size()+t.size()<<endl;
    
}