#include<bits/stdc++.h>
#define ll long long
#define lu long unsigned
#define ull unsigned long long

using namespace std;
bool sortbysec(const pair<string,int> &a,
              const pair<string,int> &b)
{
    return (a.second < b.second);
}
bool sortpair(const pair<int,int> &a,
              const pair<int,int> &b)
{
    if(a.first==b.first)
        return (a.second<b.second);
    else
        return(a.first>b.first);
}
bool s(const string &a, const string &b){
    bool ans;
    return (a.size()<b.size());
}
bool isPrime(int val){
    for(int i=2;i*i<=val;i++){
        if(val%i==0)
            return false;
    }
    return true;
}
ll int conc(ll int a,ll int b){
   stringstream ss;
   ss<<a<<b;
   ll int ans;
   ss>>ans;
   ss.clear();
   return ans;
}
ll int binexp(int a,int b){
    ll int res=1;
    while(b!=0){
        if(b&1){
            res*=a;
            b--;
        }else{
            a*=a;
            b/=2;
        }
    }
    return res;
}
int gcd(int a,int b){
    if(a%b==0){
        return b;
    }else{
        return gcd(a%b,b);
    }
}

void solve(){
    string s;
    cin>>s;
    int a[26]={0};
    for(int i=0;i<s.size();i++){
        if(a[s[i]-'a']!=0){
            cout<<"no";
            return;
        }else
            a[s[i]-'a']++;
    }
    cout<<"yes";
}


int main(){
    /*int t;
    cin>>t;
    while(t--)*/
        solve();


    return 0;
}



































































//1-(3+5-2+(3+19-(3-1-4+(9-4-(4-(1+(3)-2)-5)+8-(3-5)-1)-4)-5)-4+3-9)-4-(3+2-5)-10


















