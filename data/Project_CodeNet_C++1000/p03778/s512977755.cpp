#include <bits/stdc++.h>
using namespace std;
 
int gcd(int x,int y){
    if(y==0)return x;

    return gcd(y,x%y);
}
int lcm(int x,int y){
    return x*y/gcd(x,y);
}

int main(){

    int W,A,B;
    cin>>W>>A>>B;

    if(A<=B&&B<=(A+W)||B<=A&&A<=(W+B)){
        cout<<0<<endl;
    }else{
        if((A+W)<B){
            cout<<B-(A+W)<<endl;
        }else{
            cout<<A-(B+W)<<endl;
        }
    }

    return 0;
}