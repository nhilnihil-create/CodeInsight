#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

ll count1,count2,count4;

int main(){
    ll h,w;
    cin >> h >> w;
    vector<ll> memo(26,0);
    char a[h][w];
    for(ll i=0;i<h;i++){
        for(ll j=0;j<w;j++){
            cin >> a[i][j];
            memo[a[i][j]-'a']++;
        }
    }
    if(h%2==0&&w%2==0) count4=(h/2)*(w/2);
    else if(h%2==1&&w%2==1){
        count1=1;
        count2=h/2+w/2;
        count4=(h/2)*(w/2);
    }
    else if(h%2==1&&w%2==0){
        count2=w/2;
        count4=(h/2)*(w/2);
    }
    else if(h%2==0&&w%2==1){
        count2=h/2;
        count4=(h/2)*(w/2);
    }
    for(ll i=0;i<count1;i++){
        for(ll j=0;j<26;j++){
            if(memo[j]%4==1||memo[j]%4==3){
                memo[j]--;
                break;
            }
        }
    }
    for(ll i=0;i<count4;i++){
        for(ll j=0;j<26;j++){
            if((memo[j]%4==0&&memo[j]>0)||(memo[j]%4==2&&memo[j]>4)){
                memo[j]-=4;
                break;
            }
        }
    }
    for(ll i=0;i<count2;i++){
        for(ll j=0;j<26;j++){
            if(memo[j]%4==2||(memo[j]%4==0&&memo[j]>0)){
                memo[j]-=2;
                break;
            }
        }
    }
    bool flag=true;
    for(ll i=0;i<26;i++){
        if(memo[i]!=0) flag=false;
    }
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}  
