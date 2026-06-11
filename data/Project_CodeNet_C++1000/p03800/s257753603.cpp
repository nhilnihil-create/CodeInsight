#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    bool ok=false;

    // X S S
    int a[n]={};
    for(int i=1;i<n-1;i++){
        if(s[i]=='o') a[i+1]=a[i]^a[i-1];
        else a[i+1]=1^a[i]^a[i-1];
    }
    if(s[0]=='o' && a[n-1]==0 ){
        if((s[n-1]=='o' && a[0]==a[n-1]^a[n-2]) || s[n-1]=='x' && a[0]==a[n-1]^1^a[n-2]){
            for(int i=0;i<n;i++){
                if(a[i]==1) cout<<"W";
                else cout<<"S";
            }
            cout<<endl;
            return 0;
        }
    
    }
    if(s[0]=='x' && a[n-1]==1){
        if((s[n-1]=='o' && a[0]==a[n-1]^a[n-2]) || s[n-1]=='x' && a[0]==a[n-1]^1^a[n-2]){
            for(int i=0;i<n;i++){
                if(a[i]==1) cout<<"W";
                else cout<<"S";
            }
            cout<<endl;
            return 0;
        }
    }

    // X S W
    a[1]=1;
    for(int i=1;i<n-1;i++){
        if(s[i]=='o') a[i+1]=a[i]^a[i-1];
        else a[i+1]=1^a[i]^a[i-1];
    }
    if(s[0]=='o' && a[n-1]==1 ){
        if((s[n-1]=='o' && a[0]==a[n-1]^a[n-2]) || s[n-1]=='x' && a[0]==a[n-1]^1^a[n-2]){
            for(int i=0;i<n;i++){
                if(a[i]==1) cout<<"W";
                else cout<<"S";
            }
            cout<<endl;
            return 0;
        }
    }
    if(s[0]=='x' && a[n-1]==0){
        if((s[n-1]=='o' && a[0]==a[n-1]^a[n-2]) || s[n-1]=='x' && a[0]==a[n-1]^1^a[n-2]){
            for(int i=0;i<n;i++){
                if(a[i]==1) cout<<"W";
                else cout<<"S";
            }
            cout<<endl;
            return 0;
        }
    }

    // X W S
    a[0]=1;
    a[1]=0;
    for(int i=1;i<n-1;i++){
        if(s[i]=='o') a[i+1]=a[i]^a[i-1];
        else a[i+1]=1^a[i]^a[i-1];
    }
    if(s[0]=='o' && a[n-1]==1 ){
        if((s[n-1]=='o' && a[0]==a[n-1]^a[n-2]) || s[n-1]=='x' && a[0]==a[n-1]^1^a[n-2]){
            for(int i=0;i<n;i++){
                if(a[i]==1) cout<<"W";
                else cout<<"S";
            }
            cout<<endl;
            return 0;
        }
    }
    if(s[0]=='x' && a[n-1]==0){
        if((s[n-1]=='o' && a[0]==a[n-1]^a[n-2]) || s[n-1]=='x' && a[0]==a[n-1]^1^a[n-2]){
            for(int i=0;i<n;i++){
                if(a[i]==1) cout<<"W";
                else cout<<"S";
            }
            cout<<endl;
            return 0;
        }
    }

    // X W W
    a[0]=1;
    a[1]=1;
    for(int i=1;i<n-1;i++){
        if(s[i]=='o') a[i+1]=a[i]^a[i-1];
        else a[i+1]=1^a[i]^a[i-1];
    }
    if(s[0]=='o' && a[n-1]==0 ){
        if((s[n-1]=='o' && a[0]==a[n-1]^a[n-2]) || s[n-1]=='x' && a[0]==a[n-1]^1^a[n-2]){
            for(int i=0;i<n;i++){
                if(a[i]==1) cout<<"W";
                else cout<<"S";
            }
            cout<<endl;
            return 0;
        }
    }
    if(s[0]=='x' && a[n-1]==1){
        if((s[n-1]=='o' && a[0]==a[n-1]^a[n-2]) || s[n-1]=='x' && a[0]==a[n-1]^1^a[n-2]){
            for(int i=0;i<n;i++){
                if(a[i]==1) cout<<"W";
                else cout<<"S";
            }
            cout<<endl;
            return 0;
        }
    }

    
    cout<<-1<<endl;
    return 0;
    
}