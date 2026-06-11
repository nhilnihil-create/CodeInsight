#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,A,B,total;
    cin>>n>>A>>B;
    total = 0;
    string s;
    cin>>s;
    int b = 0;
    for(int i=0;i<n;i++){
        if(s[i] == 'c' || total >= A+B ){
            cout<<"No"<<endl;
        }else if(s[i] == 'b' && b >= B){
            cout<<"No"<<endl;
        }else if(s[i] == 'b'){
            cout<<"Yes"<<endl;
            total++;
            b++;
        }else{
            cout<<"Yes"<<endl;
            total++;
        }
    }
}
