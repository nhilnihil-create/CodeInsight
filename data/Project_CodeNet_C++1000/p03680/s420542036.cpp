#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N;
    bool canstop=false;
    vector<int> a(N);
    for(int i=0;i<N;i++) cin >> a.at(i);
    int now=0,cnt=0;
    for(int i=0;i<N;i++){
        if(now!=1){
            now = a.at(now)-1;//調整
            cnt++;
        }
        else{
            canstop = true;
            break;
        }
        
    }
    if(canstop) cout << cnt << endl;
    else cout << -1 << endl;
    return 0;
}