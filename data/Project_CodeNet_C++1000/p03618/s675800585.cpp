#include<bits/stdc++.h>
using namespace std;

int main(void){
    string a;
    cin >> a;
    vector<long long> cnt(30);
    for(int i=0;i<30;++i){cnt[i] = 0;}
    for(int i=0;i<a.size();++i){
        ++cnt[a[i]-'a'];
    }
    long long kazu = 0;
    for(int i='a';i<='z';++i){
        kazu += (cnt[i-'a']*(cnt[i-'a']-1))/2;
    }
    long long ans = ((a.size()*(a.size()-1))/2 - kazu + 1);
    cout << ans << endl;
}