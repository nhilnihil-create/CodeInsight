#include <bits/stdc++.h>
using namespace std;

bool dp[5010][5010];

int n,k;
int a[5010];



/* どちゃくそ楽な方法、実際にいい集合を作ってみた。
int ans;
int t;
int main(){

    cin >> n >> k;

    ans = n;
    t = 0;

    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    sort(a,a+n);

    for(int i=n-1; i!=-1; i--){
        if(t+a[i] < k){ //k以上の値はそれだけでいい集合()になるから省く
            t += a[i];
        }
        else{
            ans = min(ans,i);
        }
    }
    cout << ans << endl;

}*/


int main() {

    cin >> n >> k;

    for(int i=1; i<=n; i++){
        cin >> a[i];
    }

    sort(a+1,a+n+1);

    int my_left = 0,my_right = n+1;

    while(abs(my_left - my_right) > 1){

        int mid = (my_left + my_right)/2;

        for(int r=0; r<5010; r++){
            for(int w=0; w<5010; w++){
                dp[r][w] = false;
            }
        }

        dp[0][0] = true;

        bool need = false;

        for(int j=1; j<=n; j++){
            for(int t=0; t<=k; t++){
                if(dp[j-1][t]){
                    dp[j][t] = true;
                }
                if(mid!= j && t-a[j] >= 0){
                    if(dp[j-1][t-a[j]]) {
                        dp[j][t] = true;
                    }
                }

                /*if(dp[j][t] && k-a[mid] <=t && t < k){
                    need = true;
                }*/
            }
        }

        if(k>a[mid]) {
            for (int j = k - a[mid]; j < k; j++) {
                if (dp[n][j]) {
                    need = true;
                    break;
                }
            }
        }
        else{
            need = true;
        }

        if(need){
            my_right = mid;
        }
        else{
            my_left = mid;
        }
    }

    cout << my_left << endl;

    return 0;
}