#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF=1LL<<60;
const int inf=1<<30;
const int mod=1e9+7;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;cin >> n;
    int p=inf,q=0;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
        chmin(p,a[i]);
        chmax(q,a[i]);
    }
    if(q-p>1){
        cout << "No" << endl;
        return 0;
    }
    int x=0,y=0;
    for(int i=0;i<n;i++){
        if(a[i]==p){
            x++;
        }
        else{
            y++;
        }
    }
    if(p==q){
        if(p==n-1||p*2<=n){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
    else{
        if(x<q&&2*(q-x)<=y){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
}