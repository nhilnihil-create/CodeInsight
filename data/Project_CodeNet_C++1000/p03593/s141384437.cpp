#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(v) v.begin(),v.end()

using namespace std;
typedef long long ll;




int main()
{
    
    int H,W;
    cin >> H >> W;
    vector<char> S(H*W);
    rep(i,H*W) cin >> S[i];
    sort(all(S));
    
    vector<int> a;
    a.push_back(1);
    for (int i = 1; i < H*W; i++) {
        if(S[i] == S[i-1]) a.back()++;
        else a.push_back(1);
    }
    
    
    int o = 0, t = 0, f = 0;
    rep(i,int(a.size())){
        if(a[i]%4==0) f++;
        else if(a[i]%2==0) t++;
        else o++;
    }
    
    if(H%2==0 && W%2==0){
        if(o == 0 && t == 0) cout << "Yes" << endl;
        else cout << "No" << endl;
        
    }else if(H%2==0 && W%2==1){
        if(o == 0 && t <= H/2) cout << "Yes" << endl;
        else cout << "No" << endl;
        
    }else if(H%2==1 && W%2==0){
        if(o == 0 && t <= W/2) cout << "Yes" << endl;
        else cout << "No" << endl;
        
    }else if(H%2==1 && W%2==1){
        if(o == 1 && t <= H/2+W/2) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    
    return 0;
}

