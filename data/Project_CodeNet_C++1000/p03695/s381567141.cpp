#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int>a(n);
    vector<bool>b(8,0);
    int oc=0;
    for(int i=0; i<n; i++){
        cin >> a[i];
        if(a[i]<400){
            b[0]=1;
        }else if(a[i]<800){
            b[1]=1;
        }else if(a[i]<1200){
            b[2]=1;
        }else if(a[i]<1600){
            b[3]=1;
        }else if(a[i]<2000){
            b[4]=1;
        }else if(a[i]<2400){
            b[5]=1;
        }else if(a[i]<2800){
            b[6]=1;
        }else if(a[i]<3200){
            b[7]=1;
        }else{
            oc++;
        }
    }
    int cnt=0;
    for(int i=0; i<8; i++){
        if(b[i]) cnt++;
    }
    if(cnt==0) cout << 1 << " ";
    else cout << cnt << " ";
    cout << cnt + oc << endl;
    return 0;
}