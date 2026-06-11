#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); i++)
#define ALL(n) begin(n),end(n)

long long value(int bit);

string s;
int n;

int main(){
    cin>>s;
    n=s.size()-1;   // '+'が入るスペースの数
    long long sum=0; 

    for(int bit=0; bit<(1<<n); bit++){
        sum+=value(bit);
    }

    cout<<sum<<endl;
}

long long value(int bit){
    long long v=0;
    string c=s.substr(0,1);

    REP(i,n){  
        // i番目が1なら
        if(bit&(1<<i)){
            v+=stoll(c);
            c.clear();
            c=s.substr(i+1,1);
        // i番目が0なら
        }else{
            c+=s.substr(i+1,1);
        }
    }
    v+=stoll(c);
    
    return v;
}