#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <queue>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()

int main() {
    int n,l,p;
    cin>>n;
    vector<int>waru;
    vector<int>sosu(1000);
    for(int i=n;i>1;i--)waru.push_back(i);
    l=waru.size();
    while(l){
        p=waru[l-1];
        if(p>1){
            rep(i,l){
                while(waru[i]%p==0){
                    waru[i]/=p;
                    sosu[p]++;
                }
            }
        }
        waru.pop_back();
        l--;
    }
    rep(i,1000)sosu[i]++;
    long long ans=1;
    rep(i,1000){
        ans*=sosu[i];
        ans%=1000000007;
    }
    cout<<ans;
	return 0;
}
