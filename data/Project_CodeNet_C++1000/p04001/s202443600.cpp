#include <bits/stdc++.h>
#define rep(n) for(int i=0;i<(n);i++)
using namespace std;
using ll=long long;


int main() {
    string s;
    cin>>s;
    ll sum=0;
    int plus_num=int(s.length())-1;
    for(int bit=0;bit<(1<<plus_num);++bit){
        ll tmp=0;
        for(int i=0;i<plus_num;++i){
            tmp*=10;
            tmp+=stoi(string(1,s[i]));
            if(bit&(1<<i)){
                sum+=tmp;
                tmp=0;
        }
    }
    tmp*=10;
    tmp+=stoi(string(1,s.back()));
    sum+=tmp;
    }
    cout<<sum;
return 0;
}