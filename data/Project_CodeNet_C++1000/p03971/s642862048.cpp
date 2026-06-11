#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long int
#define INF 1000000007
// cin.eof() 入力個数の問題

int main(){
int n,a,b;
cin>>n>>a>>b;
string s;
cin>>s;
int join=0,os=0;
rep(i,n){
    if(s[i]=='a'){
        if(join<a+b){
            cout<<"Yes"<<endl;
            join++;
        }else{
            cout<<"No"<<endl;
        }
    }else if(s[i]=='b'){
        if(join<a+b&&os<b){
            cout<<"Yes"<<endl;
            join++;
            os++;
        }else{
            cout<<"No"<<endl;
        }
    }else{
        cout<<"No"<<endl;
    }



}

  return 0;
}
