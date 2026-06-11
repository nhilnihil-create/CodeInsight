#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
using namespace std;
int main(){
    string s;
    cin>>s;
    long long n=0,ss=0,w=0,e=0;
    f(i,0,s.size()){
        if(s[i]=='N'){
            n++;
        }
        else if(s[i]=='S'){
            ss++;
        }
        else if(s[i]=='W'){
            w++;
        }
        else{
            e++;
        }
    }
    if(n>0&&ss>0&&w==0&&e==0){
        cout<<"Yes"<<endl;
    }
    else if(n==0&&ss==0&&w>0&&e>0){
        cout<<"Yes"<<endl;
    }
    else if(n>0&&ss>0&&w>0&&e>0){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}
