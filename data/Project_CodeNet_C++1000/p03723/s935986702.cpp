#include <bits//stdc++.h>
#define rep(i,n) for(int i = 0;i < n;i++)
using namespace std;
typedef long long ll;

int main(){
    int a,b,c;
    cin>>a>>b>>c;
    int cnt=0;
    bool flag=true;
    if((a%2||b%2)||c%2)flag=false;
    else if(a==b&&b==c){
        flag=false;
        cnt=-1;
    }
    while(flag){
        int i=a,j=b,k=c;
        a=j/2+k/2;
        b=i/2+k/2;
        c=i/2+j/2;
        cnt++;
        if((a%2||b%2)||c%2)flag=false;
    }
    cout<<cnt<<endl;
    return 0;
}