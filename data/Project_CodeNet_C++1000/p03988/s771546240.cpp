#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, amax = 0;
    cin >> n;
    vector<int> cnt(n,0);
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        cnt[a]++;
        amax = max(amax, a);
    }
    for(int i=0;i<=amax;i++){
        cnt[max(i,amax-i)]--;
    }
    bool ok = true;
    if(amax == 1) ok &= n == 2;
    for(int i=1;i<=amax;i++){
        if(i <= (amax+1)/2){
            ok &= cnt[i] == 0;
        }
        else{
            ok &= cnt[i] >= 0;
        }
    }
    cout << (ok ? "Possible" : "Impossible") << endl;
    return 0;
}