#include<iostream>
#include<algorithm>

using namespace std;

#define REP(s,e) for(int i=(s);i<(e);i++)

int main(){
    string A,B;

    cin>>A>>B;
    
    if(A=="H") cout<<B<<endl;
    else if(B=="H") cout<<"D"<<endl;
    else cout<<"H"<<endl;
}
