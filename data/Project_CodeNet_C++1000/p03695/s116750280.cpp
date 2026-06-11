#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> pii;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define YN(x) cout<<(bool x?"Yes":"No")<<endl;
#define out(s) cout<<s<<endl;
#define pb push_back;
#define sp " ";
#define INF 10000000000
void vout(vector<int> v){
    for(int i=0;i<v.size();i++)
    cout<<v.at(i)<<endl;
}
int main(){
    vector<bool> ans(8,false);
    int n,count=0;
    cin>>n;
    rep(i,n){
        int a=0,j=0;  
        cin>>a;
        if(a>399) j=1;
        if(a>799) j=2;
        if(a>1199) j=3;
        if(a>1599) j=4;
        if(a>1999) j=5;
        if(a>2399) j=6;
        if(a>2799) j=7;
        if(a>3199) j=8;
        if(j==8){
            count+=1;
        }
        else{
            ans.at(j)=true;
        }
    }
    int num=0;
    rep(i,8){
        if(ans.at(i)==true){
            num+=1;
        }
    }
    int y=num+count;
    if(num==0&&count!=0){
        num+=1;
    }
    cout<<num<<" "<<y<<endl;
    
}