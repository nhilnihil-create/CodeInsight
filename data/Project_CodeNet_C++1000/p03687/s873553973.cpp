#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using Map = map<string,ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;


int main(){
    string s;
    cin >> s;
    ll N=s.size();
    char C='a';
    ll ans=s.size();
    for(ll i=0;i<26;i++){
        string s3=s;
        string s2="";
        ll counter=0;

      for(ll k=0;k<N;k++){
            //単一文字かcheck
            bool check=1;
        for(ll j=0;j<s3.size();j++){
             if(s3[j]!=C){check=0;break;}
         ;}
         if(check){ans=min(ans,counter);break;}

         for(ll j=0;j<s3.size()-1;j++){
            if(s3[j]==C||s3[j+1]==C){s2+=C;}
            else s2+=C+1;
         ;}
         s3=s2;
         s2="";
         counter++;

      ;}
        C++;
    ;}
    cout<<ans<<endl;
return 0;
}
