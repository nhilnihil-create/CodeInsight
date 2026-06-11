#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<bool> chk(n,false);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int cnt=0;
    int nx=0;
    int nw=0;
    int ans;
    while(cnt <= n+1){
        nw = nx;
        if(nw==1) break;
        nx = a[nw]-1;
        if(chk[nw]==true){
            ans = -1;
            break;
        }else{
            chk[nw] = true;
        }
        cnt++;
        ans = cnt;
        //cout << "nw " << nw << " nx " << nx << endl;
    }
    cout << ans << endl;


}

