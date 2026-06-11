#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    long long ans;
    long long cnt[26];
    cin>>s;

    ans = s.size()*(s.size()-1)/2;
    for(int i=0; i<26; i++){
        cnt[i] = 0;
    }

    for(int i=0; i<s.size(); i++){
        cnt[s[i]-'a']++;
    }


    for(int i=0; i<26; i++){
        ans -= cnt[i]*(cnt[i]-1) / 2;
    }
    
    cout<<ans+1<<endl;

    return 0;
}