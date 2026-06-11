/***

    Muhammad Imdad-Ul-Haque Rakib(Attari)
    CSE'19
    Chittagong,Bangladesh

***/


#include<bits/stdc++.h>


/**Definitions**/


#define   ld             long double
#define   ll             long long
#define   boost_         ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define   pb             push_back
#define   ppb            pop_back
#define   ull            unsigned long long
#define   over           return 0
#define   scan(i,n,a)    for(i=0;i<n;i++) cin>>a[i]
#define   MP             make_pair
#define   spc            " "

using namespace std;


/** Predefined Functions **/


int gcd(int x,int y){
    if(x==0) return y;
    else return gcd(y%x,x);
}
bool sortbysec(const pair<int,int>&a, const pair<int,int>&b){ return (a.second<b.second); }
bool sortbysecinrev(const pair<int,int>&a, const pair<int,int>&b){ return (a.second>b.second); }
bool sortbysize(string &s1,string &s2){ return s1.size() < s2.size(); }
bool sortinrev(const pair<int,int> &a, const pair<int,int> &b){ return (a.first > b.first); }


/** Main Function **/


int main(){

    boost_;
    ll n,k,x,y;
    cin>>n>>k>>x>>y;
    if(n<=k) cout<<n*x<<endl;
    else cout<<x*k+(n-k)*y<<endl;


    over;
}
