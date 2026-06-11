#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using Map = map<string,ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;


int main(){
    ll N;
    cin >> N;
    string S;
    cin >> S;
    ll Lcounter=0;
    ll Rcounter=0;
    for(ll i=0;i<N;i++){
        if(S[i]=='('){Lcounter++;}
        else if(S[i]==')'){Rcounter++;}
        if(Rcounter>Lcounter){
            N++;i++;Lcounter++;
            S='('+S;
        }
    ;}
    for(ll i=0;i<Lcounter-Rcounter;i++){
        S+=')';
    ;}
    cout<<S<<endl;
return 0;
}
