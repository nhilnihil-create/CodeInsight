#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


signed main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
    cout << fixed << setprecision(20);

    string s;
    cin>>s;
    int n=s.size();
    for(int i=0;i<n-1;i++){
        if(s[i]==s[i+1]){
            cout << i+1 << " " << i+2<<endl;
            return 0;
        }
    }
    for(int i=0;i<n-2;i++){
        int cnt[26]={};
        for(int j=0;j<3;j++){
            cnt[s[i+j]-'a']++;
            if(cnt[s[i+j]-'a']==2){
                cout << i+1 << " " << i+3 << endl;
                return 0;
            }
        }
    }
    cout << -1 << " " << -1 << endl;
    return 0;
}