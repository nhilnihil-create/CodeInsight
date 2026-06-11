#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
    int n,a,b;
    cin>>n>>a>>b;
    string s;
    cin>>s;
    int cnt=0;
    int cntb=0;
    
    rep(i,n){
        if(s[i]=='c') cout<<"No"<<endl;
        else if(cnt>=a+b) cout<<"No"<<endl;
        else if(s[i]=='a'){
            cout<<"Yes"<<endl;
            cnt++;
        }
        else if(s[i]=='b'){
            if(cntb>=b) cout<<"No"<<endl;
            else{
                cout<<"Yes"<<endl;
                cnt++;
                cntb++;
            }
        }
    }
    return 0;
}