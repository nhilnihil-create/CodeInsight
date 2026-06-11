#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int>rate(n);
    for(int i=0;i<n;i++) cin >> rate[i];
    sort(rate.begin() ,rate.end());

    int under = 0 ,upper = 399;
    vector<int>color(9 ,0);
    for(int i=0;i<8;i++){
        for(int j=0;j<n;j++){
            if(under<=rate[j] && rate[j]<=upper)color[i]++;
        } 
        under += 400;
        upper += 400;
    }
    for(int i=0;i<n;i++){
        if(rate[i]>= 3200)color[8]++;
    }

    int ans = 0;
    for(int i=0;i<8;i++){
        if(color[i] > 0)ans++;
    }
    if(ans>0){
        cout <<ans << " "<< ans + color[8] <<endl;
    }else {
        cout << "1" << " " << color[8] << endl;
    }
}