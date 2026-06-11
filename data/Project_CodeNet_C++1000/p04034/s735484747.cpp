#include <bits/stdc++.h>
using namespace std;
#define ll	    long long
#define vi      vector <int>
#define vii     vector <pair<int,int>>
#define ii      pair<int,int>
#define loop(n)	for(int i=0;i<n;i++)
#define loopj(n)	for(int j=0;j<n;j++)
ll mod=1e9+7;
const int N=2e5+7, M =53;

int L[N],R[N],Q[N];
map<int,int>mp;
map<int,int>mp1;
int main()
{
      //freopen ("output.txt","w",stdout);
        ios_base::sync_with_stdio(0), cin.tie(0),cout.tie(0);
int t,n,m;
cin >> n >> m;
mp[1]=1;
ll tot=0;
int x,y;
while(m--){
    cin >> x >> y;
    mp1[y]++;
    mp1[x]--;
    if(mp[x]){
        mp[y]=1;
        if(mp1[x]<0){
            mp[x]=0;
        }
    }
    
}
for(auto it: mp)
    tot+=it.second;
cout <<tot <<endl;
}
