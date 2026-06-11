#include <bits/stdc++.h>

using namespace std;

#define pan(i,n) for(int i=0;i<n;i++)
#define pans(i,n,a) for(int i=a;i<n;i++)
#define ll long long int
#define vi vector<int>
#define vl vector<ll>
#define pb push_back
#define INF 1000000007
#define PI 3.141592653
#define inf 100007
#define P pair<ll,ll>
ll gcd(ll a, ll b) { return a % b == 0 ? b : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

int ans=inf;
void opr(string s,int count,char c){
    int cr=0;
    string p="";
    pan(i,(int)s.size()-1){
        if(s[i]==c || s[i+1]==c) p+=c;
        else{
            cr++;
            p+=s[i];
        }
    }
    count++;
    if(cr!=0)
        opr(p,count,c);
    else {
        ans=min(ans,count);
    }
}

int main(){
    string s;
    cin>>s;
    int count=0;
    pan(i,(int)s.size()-1){
        if(s[i]==s[i+1]) count++;
    }
    if(count==(int)s.size()-1) cout<<0;
    else{
        for(int i=0;i<26;i++){
            char c='a'+i;
            opr(s,0,c);
        }
        cout<<ans;
    }
}