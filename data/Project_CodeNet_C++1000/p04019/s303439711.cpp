#include <bits/stdc++.h>
#define rep(i,n) for (int i= 0;i<(n);++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;


int main(){
    bool w = false;
    bool s = false;
    bool n =false;
    bool e =false;
    string N;
    cin>>N;

    for(int i =0;i<N.length();++i){
        char x = N[i];
        if(x=='N'){
            n=true;
        }
        if(x=='W'){
            w=true;
        }
        if(x=='S'){
            s=true;
        }
        if(x=='E'){
            e=true;
        }

    }
    if(n==s&&e==w){
        cout <<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }

}
