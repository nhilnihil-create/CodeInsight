/*    Mohammed Sami Khan
                       মোহাম্মদ সামী খান
*/
#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1.0)
#define endl "\n"
#define mp(a,b) make_pair(a,b)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef long long ll;
typedef unsigned long long ull;

bool sortbysecc(const pair<int,int> &a, const pair<int,int> &b){
    return (a.second < b.second);
}

int main()
{
    fastio;
    ll t, n, sum=0, x, y, p, q, r, i, j, d, f=0, char_count[26]={0};
    //char *ye="YES", *no="NO";
    map<int, int> mp;
    map<int, int> :: iterator it;
    cin>>n;
    ll a[n];
    for(i=0;i<n;i++){
        cin>>a[i];
        if(mp.count(a[i])) mp[a[i]]++;
        else mp[a[i]]=1;
    }
    for(it=mp.begin();it!=mp.end();it++){
        if((*it).second%2) f++;
    }
    cout<<f;
}
