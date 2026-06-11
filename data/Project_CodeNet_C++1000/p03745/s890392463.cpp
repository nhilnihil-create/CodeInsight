#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (ll i=0; i<(ll)(n); i++)
#define repd(i,n) for (ll i=n-1; i>=0; i--)
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define PF push_front
#define PB push_back
int main()
{
    ll N; cin >> N;
    vector<ll> A(N);
    rep(i,N){
        cin >> A.at(i);
    }
    ll count=1;
    int judge=0;
    rep(i,N-1){
        if(i!=0){
            if(judge==2){
                if(A.at(i)>A.at(i+1)){
                    count++;
                    judge=1;
                    continue;
                }
                if(A.at(i)==A.at(i+1)){
                    continue;
                }
            }
            if(judge==0){
                if(A.at(i)<A.at(i+1)){
                    count++;
                    judge=1;
                    continue;
                }
                if(A.at(i)==A.at(i+1)){
                    continue;
                }
            }
        }
        if(A.at(i)<A.at(i+1)){
            judge=2;
        }
        else if(A.at(i)>A.at(i+1)){
            judge=0;
        }
        else if(A.at(i)==A.at(i+1)){
            judge=1;
        }
    }
    cout << count << endl;
}