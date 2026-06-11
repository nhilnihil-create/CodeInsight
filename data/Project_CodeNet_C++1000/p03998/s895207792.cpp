#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    string a,b,c;
    cin>>a>>b>>c;
    a+='G';
    b+='G';
    c+='G';
    int A=0,B=0,C=0,now=0;
    while(1){
        if(A==a.size()){
            cout<<'A'<<endl;
            return 0;
        }
        if(B==b.size()){
            cout<<'B'<<endl;
            return 0;
        }
        if(C==c.size()){
            cout<<'C'<<endl;
            return 0;
        }
        if(now==0){
            now=a[A]-'a';
            A++;
        }
        else if(now==1){
            now=b[B]-'a';
            B++;
        }
        else{
            now=c[C]-'a';
            C++;
        }
    }
}