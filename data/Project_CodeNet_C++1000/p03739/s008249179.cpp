#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i=0; i<n; i++){
        cin >> a.at(i);
    }
    ll cnt1=0,cnt2=0;
    ll tot=0;
    for(int i=0; i<n;i++){
        ll after;
        if(i%2==0){
            after=max(a.at(i), 1-tot);
        }
        else{
            after=min(-1-tot, a.at(i));
        }
        tot+=after;
        cnt1+=abs(after-a.at(i));
    }
    tot=0;
    for(int i=0; i<n;i++){
        ll after;
        if(i%2==1){
            after=max(a.at(i), 1-tot);
        }
        else{
            after=min(-1-tot, a.at(i));
        }
        tot+=after;
        cnt2+=abs(after-a.at(i));
    }
    cout << min(cnt1, cnt2) << endl;
}