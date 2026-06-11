#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    vector<ll> num(26,0);
    ll H,W;
    cin >> H >>W;
    for(int i=0;i<H;i++){
        string S;
        cin >> S;
        for(int j=0;j<W;j++){
            num[S[j]-'a']++;
        }
    }
    ll remain4 = (H/2)*(W/2);
    ll remain2 = (H*W -remain4*4)/2;
    ll remain1 = H*W -remain4*4 -remain2*2;
    for(int i=0;i<26;i++){
        ll temp = num[i]/4;
        remain4-=temp;
        num[i] -= temp*4;
        temp = num[i]/2;
        remain2-=temp;
        num[i] -= temp*2;
        remain1-= num[i];
    }

    if(remain1==0 && remain4<=0){
        cout << "Yes" << endl;
    }else{
        cout <<"No" << endl;
    }
    return 0;
}