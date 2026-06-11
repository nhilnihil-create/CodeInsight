#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;

int MOD=1e9+7;
ll INF=1e18;

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

int main(){
    int n; cin>>n;
    ll sum=0;
    for(int i=1; i<=1e7; i++){
        sum+=i;
        if(n<sum){
            for(int j=1; j<=i; j++){
                if(j==sum-n) continue;
                cout << j << endl;
            }
            return 0;
        }
    }
}