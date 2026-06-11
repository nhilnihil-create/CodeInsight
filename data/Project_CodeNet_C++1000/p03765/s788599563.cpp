#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


signed main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
    cout << fixed << setprecision(20);

    string s,t;
    cin>>s>>t;
    int n=s.size(), m=t.size();
    int a[n+1]={},b[m+1]={};
    for(int i=0;i<n;i++){
        a[i+1] = a[i];
        if(s[i]=='A') a[i+1]++;
        else a[i+1]--;
    }
    for(int i=0;i<m;i++){
        b[i+1] = b[i];
        if(t[i]=='A') b[i+1]++;
        else b[i+1]--;
    }
    int q;
    cin>>q;
    while(q--){
        int i,j,k,l;
        cin>>i>>j>>k>>l;
        i--,k--;
        if((a[j] - a[i] - b[l] + b[k])%3==0){
            cout << "YES\n";
        }
        else cout << "NO\n";
    }
}