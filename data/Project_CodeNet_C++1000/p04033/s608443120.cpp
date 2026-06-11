#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
using namespace std;
int main(){
    long long a,b;
    cin>>a>>b;
    if(a>0&&b>0){
        cout<<"Positive"<<endl;
    }
    else if(a<0&&b<0){
        if((b-a)%2==0){
            cout<<"Negative"<<endl;
        }
        else{
            cout<<"Positive"<<endl;
        }
    }
    else{
        cout<<"Zero"<<endl;
    }
    return 0;
}
