#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pii pair<int,int>
const long long MOD=1000000007;

int main(){
    string a,b;
    cin>>a>>b;
    int ans=0;//-1はbのほうが大きい,0は同じ,1はaのほうが大きい
    if(a.size()==b.size()){
        rep(i,a.size()){
            if(a[i]>b[i]){
                ans=1;
                break;
            }
            else if(a[i]<b[i]){
                ans=-1;
                break;
            }
        }
    }
    else{
        if(a.size()>b.size()) ans=1;
        else ans=-1;
    }
    if(ans==1) cout<<"GREATER"<<endl;
    else if(ans==-1) cout<<"LESS"<<endl;
    else cout<<"EQUAL"<<endl;
    return 0;
}