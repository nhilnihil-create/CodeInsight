#include <bits/stdc++.h>

using namespace std;

#define pan(i,n) for(int i=0;i<n;i++)
#define pans(i,n,a) for(int i=a;i<n;i++)
#define ll long long int
#define vi vector<ll>
#define vl vector<ll>
#define pb push_back
#define INF 1000000007
#define PI 3.141592653
#define inf 100007
#define pll pair<ll,ll>
#define pii pair<int,int>
ll gcd(ll a, ll b) { return a % b == 0 ? b : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

int main(){
    string s;
    cin>>s;
    int n=s.size(),ans=0,scount=0,tcount=0;
    stack<char> stk;
    pan(i,n){
        if(s[i]=='S'){
            stk.push(s[i]);
        }
        else if(s[i]=='T'){
            if(!stk.empty()){
                if(stk.top()=='S') stk.pop();
                else if(stk.top()=='T') stk.push(s[i]);
            }
            else stk.push(s[i]);
        }
    }
    cout<<stk.size();
}
