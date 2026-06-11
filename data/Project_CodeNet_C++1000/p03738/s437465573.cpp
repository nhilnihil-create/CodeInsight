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


int _find(string &a,string &b){
    
    for(int i=0;i<a.l();i++){
        if(a[i]!=b[i]){
            return (a[i]>b[i]) ? 1 : -1;
        }
    }
    return 0;
}
void equality(string &a,string &b){
    if(a.l()<b.l()){
        reverse(all(a));
        while(a.l()<b.l()){
            a.pb('0');
        }
        reverse(all(a));
    }
    
    if(a.l()>b.l()){
        reverse(all(b));
        while(a.l()>b.l()){
            b.pb('0');
        }
        reverse(all(b));
    }
}
void solve(){
    
    string a,b;
    cin>>a>>b;
    
    equality(a,b);
    
    int f=_find(a,b);
    if(f>0){
        cout<<"GREATER";
    }
    else if(f==0){
        cout<<"EQUAL";
    }
    else{
        cout<<"LESS";
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