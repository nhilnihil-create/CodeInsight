#include<bits/stdc++.h>
using namespace std;

int n;

int main(void){
    cin >> n;
    vector<int> c(9, 0);
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        if(a >= 3200) c[8]++;
        else c[a/400]++;
    }
    int res1=0, res2;
    for(int i = 0; i < 8; i++){
        if(c[i]>0){
            res1++;
        }
    }
    if(res1 == 0){
        res1 = 1;
        c[8]--;
    }
    res2 = res1+c[8];
    cout << res1 << " " << res2 << endl;
    return 0;
}
