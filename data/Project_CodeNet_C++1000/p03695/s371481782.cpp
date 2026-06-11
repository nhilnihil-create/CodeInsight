#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;

int main() {
    int n,temp,cnt=0;;
    cin>>n;
    map<int,int> mp;
    rep(i,n) {
        cin>>temp;
        if (temp<=399) mp[0]++;
        else if(temp<=799) mp[1]++;
        else if(temp<=1199) mp[2]++;
        else if(temp<=1599) mp[3]++;
        else if(temp<=1999) mp[4]++;
        else if(temp<=2399) mp[5]++;
        else if(temp<=2799) mp[6]++;
        else if(temp<=3199) mp[7]++;
        else cnt++; 
    }
    if (mp.size()==0&&cnt!=0) cout<<1<<" "<<cnt<<endl;
    else cout<<mp.size()<<" "<<mp.size()+cnt<<endl;
}
