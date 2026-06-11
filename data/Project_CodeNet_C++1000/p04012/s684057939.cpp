#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define faster ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
 
typedef vector<int> vi;;
typedef vector<ll> vll;

#define l() length()
#define sz() size()
 
#define b() begin()
#define e() end()
#define all(x) x.begin(), x.end()
 
#define pb(i) push_back(i)
#define PB() pop_back()
 
 
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define Fi first
#define Se second
 
const int maxx=1e6+9;
 
// Happy Coding!

bool _find(vi &freq){
    for(int i=0;i<26;i++){
        if(freq[i]&1)
            return false;
    }
    return 1;
}
void solve(){
    string str;
    cin>>str;
    vi freq(26,0);
    for(char ch:str){
        freq[ch-'a']++;
    }
    if(_find(freq)){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
}



int main() {
    faster;
    int t=1;
    // cin>>t;
    while(t-->0){
        solve();
    }
	return 0;
}