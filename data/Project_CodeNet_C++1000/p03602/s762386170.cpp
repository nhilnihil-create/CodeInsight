#include<bits/stdc++.h>
using namespace std;

int main(){

    int n; cin >> n;
    vector<vector<int> > a(n, vector<int> (n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }

    bool flag = true;

    //存在判定

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            for(int k = 0; k < n; k++){
                if(a[i][j] > a[i][k] + a[k][j]){
                    flag = false;
                    break;
                }
            }

            if(!flag) break;
        }
        if(!flag) break;
    }


    if(!flag) cout << -1 << endl;
    else{

        long long ans = 0;

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){

                bool flag = false;
                //(i, j)を取り除いてもいいですか？
                for(int k = 0; k < n; k++){
                    if(k == i || k == j) continue;


                    if(a[i][j] == a[i][k] + a[k][j]){
                        flag = true;
                        break;
                    }
                }

                if(!flag) ans += (long long)a[i][j];

            }
        }
    
        cout << ans << endl;
    }

    //cout << ans << endl;

    return 0;
}
