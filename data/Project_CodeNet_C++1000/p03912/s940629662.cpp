#include <bits/stdc++.h>
using namespace std;
const int MAX_X=1e5+10;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,M; cin >> N >> M;
    vector<int> cnt(MAX_X,0);
    for (int i=0;i<N;++i){
        int X; cin >> X;
        ++cnt[X];
    }
    int ans=0;
    for (int i=0;2*i<=M;++i){
        int sum1=0,sum2=0,sum3=0,sum4=0;
        for (int j=i;j<MAX_X;j+=M){
            sum1+=cnt[j]; sum2+=cnt[j]&1;
        }
        if (2*i%M==0){ans+=sum1/2; continue;}
        for (int j=(M-i)%M;j<MAX_X;j+=M){
            sum3+=cnt[j]; sum4+=cnt[j]&1;
        }
        if (sum1<sum3) ans+=sum1+(sum3-max(sum1,sum4))/2;
        else ans+=sum3+(sum1-max(sum3,sum2))/2;
    }
    cout << ans << '\n';
}