#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n,w;
    cin >> n >> w;
    vector<long long> v[4];
    long long w1,v1;
    cin >> w1 >> v1;
    v[0].push_back(v1);
    for(int i=1; i<n; i++){
        long long a,b;
        cin >> a >> b;
        v[a-w1].push_back(b);
    }
    for(int i=0; i<4; i++){
        sort(v[i].begin(),v[i].end(),greater<long long>());
    }
    long long sum[4][n+1];
    for(int i=0; i<4; i++){
        sum[i][0] = 0;
        for(int j=0; j<v[i].size(); j++){
            sum[i][j+1] = sum[i][j] + v[i][j];
        }
    }
    long long ans = 0;
    for(long long p=0; p<=v[0].size(); p++){
        for(long long q=0; q<=v[1].size(); q++){
            for(long long r=0; r<=v[2].size(); r++){
                for(long long s=0; s<=v[3].size(); s++){
                    if(w1*(p+q+r+s)+q+2*r+3*s <= w){
                        ans = max(ans,sum[0][p]+sum[1][q]+sum[2][r]+sum[3][s]);
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
