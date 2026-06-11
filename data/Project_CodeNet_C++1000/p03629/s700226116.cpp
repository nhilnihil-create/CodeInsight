#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
vi pos[30];
const int maxn=2e5+5;
int dp[maxn];
int inv[maxn];
signed main() {
    string str;
    cin>>str;
    int n=str.length();
    for(int i=0 ; i<26 ; i++) {
        pos[i].push_back(0);
    }
    for(int i=0 ; i<n ; i++) {
        char c=str[i];
        pos[(int)c-'a'].push_back(i+1);
        //cout<<(int)c-'a'<<" "<<i+1<<endl;
    }
    for(int i=0; i<26 ; i++) {
        pos[i].push_back(n+1);
    }
    dp[0]=0;
    //cout<<"n = "<<n<<endl;
    for(int i=1 ; i<=n+1 ; i++) {
        dp[i]=maxn;
        for(int j=0 ; j<26 ; j++) {
            int id=lower_bound(pos[j].begin(),pos[j].end(),i)-pos[j].begin();
            dp[i]=min(dp[i],dp[pos[j][id-1]]+1);
        }
    }
    inv[n+1]=0;
    for(int i=n ; i>=0 ; i--) {
        inv[i]=maxn;
        for(int j=0 ; j<26 ; j++) {
            int id=upper_bound(pos[j].begin(),pos[j].end(),i)-pos[j].begin();
            inv[i]=min(inv[i],inv[pos[j][id]]+1);
        }
    }
    //cout<<"dp okay"<<endl;
    string ans="";
    int cur=0;
    int t=0;
	while(cur!=n+1) {
		for(int i=0 ; i<26 ; i++) {
			int temp=upper_bound(pos[i].begin(),pos[i].end(),cur)-pos[i].begin();
			if(dp[pos[i][temp]]+inv[pos[i][temp]]==inv[0]&&dp[pos[i][temp]]==t+1) {
				t++;
				ans+=char(i+'a');
				cur=pos[i][temp];
				break;
			}
		}
	}
	cout<<ans;
}
