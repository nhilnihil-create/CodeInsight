#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mxn= 5e5+5;
#define mod 1000000007
#define endl '\n'
void rishabh(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int main(){
    rishabh();
    int a,b;
    cin>>a>>b;
    if(a>0){
        cout<<"Positive";
        return 0;
    }
    if(a<0&&b>0){
        cout<<"Zero";
        return 0;
    }
    else{
        a=abs(a)-abs(b)+1;
        if(a%2==0){
            cout<<"Positive";
        }
        else cout<<"Negative";
        return 0;
    }
}

