#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll mxn= 2e5+5;
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
    int a,b,c;
    cin>>a>>b>>c;
    bool f=false;
    for(int i=1;i<=100;i++){
        if((i*a)%b==c){
            f=f|true;
        }
    }
    if(f)cout<<"YES";
    else cout<<"NO";
}