#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF= 1LL << 60;
#define REP(i,n) for(ll i=0; i<n; i++)
#define FOR(i,a,n) for(ll i=a; i<n; i++)

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll h,w,n;
    cin >> h >> w >> n;
    vector<int>A(n);
    REP(i,n) cin >> A[i];
    ll cnt= A[0];
    ll col= 1;
    REP(i, h){
        if(i%2==0){
            REP(j, w){
                if(cnt==0){
                    cnt= A[col];
                    col++;
                }
                cout << col << ((j==w-1)?"":" ");
                cnt--;
    
            } cout << endl;
        }else{
            string s="";
            for(ll j=w-1; j>=0; j--){
                if(cnt==0){
                    cnt= A[col];
                    col++;
                }
                s= ((j==0)?"":" ")+to_string(col)+s;
                
                cnt--;

            } cout << s << endl;
        }

    }
    // vector<vector<ll>> map(h,vector<ll>(m,0));

    

}