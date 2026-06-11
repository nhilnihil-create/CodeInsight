#include<bits/stdc++.h>
#define ll long long
#define inf 999999999999
#define F first
#define S second
#define read(x)  freopen("input.txt","r",stdin);
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pi 2*acos(0.0)
#define ee exp(1)
#define mx 200009
using namespace std;
map<char,ll>m;
int main(){//read(x);
//fast;
ll a,b,c,d,e,f,g,h,i,j,k,l=0,n,t;
string s;
cin>>s;
n=s.size();
for(i=0;i<n;i++){
    m[s[i]]++;
}
for(auto i:m){
    b=i.S;
    char aa=i.F;
    if(b&1){
        l++;
        break;
    }
}
if(l==0)cout<<"Yes\n";
else cout<<"No\n";

}












