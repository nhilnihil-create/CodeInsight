#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define INF 1LL<<60
#define pi 3.14159265358979323846
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return true;} return false;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return true;} return false;}

int main(){
    string s;cin>>s;
    vector<int> num(4,0);//w,e,n,sの個数

    for(ll i=0;i<s.size();i++){
        if(s[i]=='W'){
            num[0]=1;
        }else if(s[i]=='E'){
            num[1]=1;
        }else if(s[i]=='N'){
            num[2]=1;
        }else if(s[i]=='S'){
            num[3]=1;
        }
    }

    int number=0;
    for(int i=0;i<4;i++){
        if(num[i]){number++;}
    }

    if(number%2==1){
        cout<<"No"<<endl;
    }else{
        if((num[0] && num[1])||(num[2] && num[3])||(num[0] && num[1] && num[2] && num[3])) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

    return 0;
}