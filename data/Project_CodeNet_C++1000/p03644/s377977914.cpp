#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int ans = 0;
    int divNum = -1;
    for(int i = 0; i < n; i++){
        int target = i + 1;
        int tmpCnt = 0;
        while(target%2==0){
            target/=2;
            tmpCnt++;
            if(target==0)break;
        }
        if(tmpCnt>divNum){
            ans = i + 1;
            divNum = tmpCnt;
        }

    }
    cout << ans << endl;
}