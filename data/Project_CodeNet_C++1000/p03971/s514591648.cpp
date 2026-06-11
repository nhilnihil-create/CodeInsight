#include <bits/stdc++.h>
using namespace std;
int main(void){
    // Your code here!
    int n,a,b;
    
    cin>>n>>a>>b;
    
    string s;
    cin>>s;
    int cnt = 0;
    int fct = 0;
    for(int i=0;i<s.size();i++){
        if(s[i] == 'a') {
            if(cnt < a+b) {
                cout<<"Yes"<<endl;
                ++cnt;
            }
            else cout<<"No"<<endl;
        } 
        else if(s[i] == 'b') {
            if(cnt < a+b && fct < b){
                cout<<"Yes"<<endl;
                ++cnt;
                ++fct;
            }
            else cout<<"No"<<endl;
        }
        else {
            cout<<"No"<<endl;
        }
    }
}
