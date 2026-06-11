#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
using P=pair<int,int>;
int main() {
    int n;cin>>n;
    vector<int> s(n);
    int sum=0;
    vector<int> rest(0);
    rep(i,n){
        cin>>s[i];
        if(s[i]%10==0) sum+=s[i];
        else rest.push_back(s[i]);
    }
    int rest_sum=0;
    if(rest.size()==0) cout<<0<<endl;
    else{
        rep(i,rest.size()){
            rest_sum+=rest[i];
        }

        if(rest_sum%10!=0) sum+=rest_sum;
        else{
            sort(rest.begin(),rest.end());
            rest_sum-=rest[0];
            sum+=rest_sum;
        }
        cout<<sum<<endl;
    }

}