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
    int n;
    cin>>n;
    string s;
    cin>>s;
    int x=0,ans=0;
    for(auto k: s){
        if(k=='I')x++;
        else x--;
        ans=max(ans,x);
    }
    cout<<ans;
}

