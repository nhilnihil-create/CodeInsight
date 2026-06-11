#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define rep(i, n) for(int i=0;i<n;++i)
#define rrep(i, n) for(int i=n;i>=0;--i)
const int inf=1e9+7;
const ll mod=1e9+7;
const ll big=1e18;
const double PI=3.14159265359;

int main() {
    string S;
    cin>>S;
    ll ans = 0;
    vector<string> arr;
    for(int bit=0;bit<(1<<(S.size()-1));++bit){
        arr.clear();
        arr.push_back(string()+S[0]);
        for(int i=0;i<S.size()-1;++i){
            if((bit&(1<<i))!=0) arr.push_back(string()+S[i+1]);
            else arr[arr.size()-1] += S[i+1];
        }
        for(int i=0;i<arr.size();++i){
            ans += stol(arr[i]);
        }
    }
    cout<<ans<<endl;
}

