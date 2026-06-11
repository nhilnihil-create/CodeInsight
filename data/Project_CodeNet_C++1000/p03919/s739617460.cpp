#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
constexpr double EPS = 1e-12;
constexpr int INF = numeric_limits<int>::max()/2;
constexpr int MOD = 1e9+7;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int h,w;cin>>h>>w;
    char res='A';
    vector<vector<string>> s(h,vector<string>(w));
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>s[i][j];
            if(s[i][j]=="snuke"){
                res += j;
                cout<<res<<i+1<<endl;
                return 0;
            } 
        }
    }
}
