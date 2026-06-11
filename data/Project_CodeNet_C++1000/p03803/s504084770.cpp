#include<iostream>
#include<algorithm>

using namespace std;

#define REP(s,e) for(int i=(s);i<(e);i++)

int main(){
    int A,B;
    cin>>A>>B;

    if(A==B) cout<<"Draw"<<endl;
    else if(A==1&&B==13) cout<<"Alice"<<endl;
    else if(A==13&&B==1) cout<<"Bob"<<endl;
    else if(A>B) cout<<"Alice"<<endl;
    else cout<<"Bob"<<endl;
}
