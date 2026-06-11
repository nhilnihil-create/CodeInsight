#include<bits/stdc++.h>
using namespace std;

static const int INF=1e9;
static const int MOD=1000000007;
typedef long long ll;
typedef pair<int,int> P;

int main(){
    int H,W; cin >> H >> W;
    char a[H][W];
    map<char,int> ma;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin >> a[i][j];
            ma[a[i][j]]++;
        }
    }
    map<char,int> ma2;
    for(auto it=ma.begin();it!=ma.end();it++){
        it->second%=4;
        if(it->second>0){
            ma2[it->first]+=it->second;
        }
    }
    int even=0;
    int odd=0;
    for(auto it=ma2.begin();it!=ma2.end();it++){
        it->second%=2;
        if(it->second==0) even++;
        else odd++;
    }
    bool flag1=false;
    if(H%2==1&&W%2==1) flag1=true;
    if(flag1){
        if(even<(H%2*W+W%2*H)/2){
            if(odd<=1){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }else{
        if(even<=(H%2*W+W%2*H)/2){
            if(odd==0){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    
    cout << "No" << endl;
}