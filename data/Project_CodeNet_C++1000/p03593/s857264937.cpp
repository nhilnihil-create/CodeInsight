#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
using P = pair<ll,ll>;
using ld=long double;

int main(){
    int h,w;cin >>h>>w;
    vector<string>s(h);
    for (int i = 0; i < h; ++i) {
        cin >>s[i];
    }
    vector<int>al(26,0);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
           al[s[i][j]-'a']++;
        }
    }
    if(h%2==0&&w%2==0){
        for (int i = 0; i < 26; ++i) {
            if(al[i]%4!=0){
                puts("No");
                return 0;
            }
        }
        puts("Yes");
    }
    else if(h%2==1&&w%2==1){
        int k=h/2+w/2;
        int cnt1=0;
        int cnt2=0;
        for (int i = 0; i < 26; ++i) {
//            cout <<char('a'+i)<<" "<<al[i]<<endl;
            if(al[i]%4==1){
                cnt1++;
                if(cnt1>1){
                    puts("No");
                    return 0;
                }
            }
            if(al[i]%4==2){
                cnt2++;
                if(cnt2>k){
                    puts("No");
                    return 0;
                }
            }
        }
        if(cnt1==0){
            puts("No");
        }
        else {
            puts("Yes");
        }
    }
    else {
        int k;
        if(h%2==1)k=w/2;
        else k=h/2;
        int cnt2=0;
        for (int i = 0; i < 26; ++i) {
            if(al[i]%4==0)continue;
            if(al[i]%4==2)cnt2++;
            else {
                puts("No");
                return 0;
            }
            if(cnt2>k){
                puts("No");
                return 0;
            }
        }
        puts("Yes");
    }
}
