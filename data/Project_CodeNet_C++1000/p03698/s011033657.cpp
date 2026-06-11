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

// 1 way is to find compute all the sorted permutations and find the 
// positions of the current permutation.


bool _find(string &str){
    set<char> s;
    for(char ch:str){
        if(s.count(ch)>0){
            return false;
        }
        s.insert(ch);
    }
    return 1;
}
void solve(){
    string str;
    cin>>str;
    if(_find(str)){
        cout<<"yes";
    }
    else{
        cout<<"no";
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