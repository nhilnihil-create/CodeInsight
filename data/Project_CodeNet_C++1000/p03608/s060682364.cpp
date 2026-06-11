#include <bits/stdc++.h>

using namespace std;

int main(){
    long long int N,M,R,ans=0;
    cin >> N >> M >> R;
    vector<int> r(R);

    for(int i=0;i<R;i++){
        cin >> r[i];
        r[i]--;
    }

    sort(r.begin(),r.end());

    long long int d[N][N];

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i==j){
                d[i][j] = 0;
            }else{
                d[i][j] = 1e9;
            }
        }
    }

    for(int i=0;i<M;i++){
        int a,b,t;
        cin >> a >> b >> t;
        a--;
        b--;
        d[a][b] = t;
        d[b][a] = t;
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<N;k++){
                d[j][k] = min(d[j][k],d[j][i]+d[i][k]);
            }
        }
    }

    do{
        long long int tmp = 0;
        for(int i=1;i<R;i++){
            tmp += d[r[i-1]][r[i]];
        }
        
        if(ans==0){
            ans = tmp;
        }else{
            ans = min(ans,tmp);
        }
    }while(next_permutation(r.begin(),r.end()));

    cout << ans << endl;
}