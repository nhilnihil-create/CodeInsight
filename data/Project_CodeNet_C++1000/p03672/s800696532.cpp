#include<iostream>
using namespace std;
int main(){
    string str;
    cin >> str;
    int n;
    n = str.size();
    string tmp1,tmp2;
    int mx=0;
    for(int i=1;i<n/2;i++){
        tmp1 = str.substr(0,i);
        tmp2 = str.substr(i,i);
        //cout << "i, tmp1, tmp2 = " << i << tmp1 << tmp2 << endl;
        if(tmp1 == tmp2){
            mx = tmp1.size()+tmp2.size();
        }
    }
    int ans;
    ans = mx;
    cout << ans << endl;
}

