#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int mxn= 1e6+5;
// check for forloop
// intialize variable
// overflow
// go for easy solution
#define mod 1000000007
ll INF = 1000000000000000005LL;
#define endl '\n'
void rishabh(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int main(){
    rishabh();
    string a,b;
    cin>>a>>b;
    if(a.size()>b.size()){
        cout<<"GREATER";
    }
    else if(a.size()<b.size()){
        cout<<"LESS";
    }
    else {
        for(int i=0;i<a.size();i++){
            if(a[i]==b[i])continue;
            else if(a[i]<b[i]){
                cout<<"LESS";
                return 0;
            }
            else {
                cout<<"GREATER";
                return 0;
            }
        }
        cout<<"EQUAL";
    }
}