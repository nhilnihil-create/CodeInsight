/**
*    author:  souzai32
*    created: 19.08.2020 00:26:47
**/

#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
typedef long long ll;
using namespace std;

int main() {

    string s;
    cin >> s;
    int n=s.size();

    ll sum,num,ans=0;

    for(int bit=0; bit<(1<<n-1); bit++){
        sum=0;
        num=s.at(0)-'0';
        for(int i=0; i<n-1; i++){
            if(bit&(1<<i)){
                sum+=num;
                num=0;
            }else{
                num*=10;
            }
            num+=s.at(i+1)-'0';
        }
            // cout << num << endl;
        if(num) sum+=num;
        ans+=sum;
        // cout << sum << endl;
    }
        cout << ans << endl;
    // num=s.at(0)-'0'+s.at(1)-'0';
    // cout << num << endl;

    return 0;
}