#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    int H,W;
    cin >> H >> W;
    vector<string> A(H);
    rep(i,H) cin >> A[i];
    map<char,int> mp;
    rep(i,H)rep(j,W){
        mp[A[i][j]]++;
    }
    int p4=0,p2=0,p1=0;
    p4 = (H/2) * (W/2);
    if(H%2==1){
        p2+=W/2;
    }
    if(W%2==1){
        p2+=H/2;
    }
    if(H%2==1&&W%2==1){
        p1=1;
    }
    while(true){
        bool done = false;
        if(p1==1){
            for(char c='a';c<='z';c++){
                if(mp[c]%2==1){
                    mp[c]--;
                    p1=0;
                    done = true;
                    break;
                }
            }
            if(p1==1){
                cout << "No" << endl;
                return 0;
            }
        }
        if(done==false&&p2>0){
            for(char c='a';c<='z';c++){
                if(mp[c]>0&&mp[c]%4==2){
                    mp[c]-=2;
                    p2--;
                    done = true;
                    break;
                }
            }
            if(!done){
                for(char c='a';c<='z';c++){
                    if(mp[c]>0&&mp[c]%4==0){
                        mp[c]-=2;
                        p2--;
                        done=true;
                        break;
                    }
                }
                if(!done){
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
        if(done==false&&p4>0){
            for(char c='a';c<='z';c++){
                if(mp[c]>0&&mp[c]%4==0){
                    mp[c]-=4;
                    p4--;
                    done = true;
                    break;
                }
            }
        }
        if(!done){
            cout << "No" << endl;
            return 0;
        }
        if(p1==0&&p2==0&&p4==0){
            bool f = true;
            for(char c='a';c<='z';c++){
                if(mp[c]>0) f=false;
            }
            if(f){
                cout << "Yes" << endl;
                return 0;
            }else{
                cout << "No" << endl;
                return 0;
            }
        }
    }
    return 0;
}