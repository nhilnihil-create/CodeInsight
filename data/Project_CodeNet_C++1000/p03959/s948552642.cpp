#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
int main(void){
    int n;
    cin >> n;
    vector<int> t(n);
    vector<bool> dt(n, false);
    vector<int> a(n);
    vector<bool> da(n, false);
    dt[0] = true;
    da[n-1] = true;
    for(int i=0; i<n; i++){
        cin >> t[i];
        if(i>0){
            if(t[i]>t[i-1]){
                dt[i]=true;
            }
        }
    }
    for(int i=0; i<n; i++){
        cin >> a[i];
        if(i>0){
            if(a[i-1]>a[i]){
                da[i-1]=true;
            }
        }
    }
    long long ans = 1;
    for(int i=0; i<n; i++){
        if(da[i]){
            if(dt[i]){
                if(a[i]!=t[i]){
                    ans = 0;
                }
            }else{
                if(a[i]>t[i]){
                    ans = 0;
                }
            }
        }else{
            if(dt[i]){
                if(t[i]>a[i]){
                    ans = 0;
                }
            }else{
                ans *= min(t[i],a[i]);
            }
        }
        ans = ans%(1000000000+7);
    }
    cout << ans << endl;
}