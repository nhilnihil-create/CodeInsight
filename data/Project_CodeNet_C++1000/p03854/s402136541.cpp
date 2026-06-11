#include<bits/stdc++.h>
using namespace std;
using Graph=vector<vector<int>>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
typedef long long ll;
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main(){
    string S;
    cin>>S;
    reverse(S.begin(),S.end());
    bool flag=true;
    string S1="maerd";
    string S2="remaerd";
    string S3="esare";
    string S4="resare";
    int i=0;
    while(i<S.size()){
        if(!flag){
            break;
        }
        bool flag2=false;
        if(S.substr(i,5)==S1){
            i=i+5;
            flag2=true;
        }
        else if(S.substr(i,5)==S3){
            i=i+5;
            flag2=true;
        }
        else if(S.substr(i,7)==S2){
            i=i+7;
            flag2=true;
        }
        else if(S.substr(i,6)==S4){
            i=i+6;
            flag2=true;
        }
        if(flag2==false){
            flag=false;
        }
    }
    if(flag){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}