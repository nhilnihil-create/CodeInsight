#include<iostream>
using namespace std;
int main(void){
    int n;
    cin>>n;
    int a[100000]={0};
    int tmp;
    for(int i(0);i<n;i++){
        cin>>tmp;
        a[tmp-1]++;
    }
    bool flag(true);
    for(int i(0);i<n;i++){
        if(n%2 == 0){
            if(i%2 == 0){
                if(a[i] != 2)flag = false;
            }
            else{
                if(a[i] != 0)flag = false;
            }
        }
        else{
            if(i%2 == 1){
                if(a[i] != 2)flag = false;
            }
            else{
                if(a[i] != 0)flag = false;
            }
        }
    }
    if(flag){
        int num = n/2;
        int ans(1);
        for(int i(0);i<num;i++){
            ans *= 2;
            if(ans >= 1000000007)ans %= 1000000007;
        }
        cout<<ans<<endl;
    }
    else cout<<0<<endl;
    return 0;
}