#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main(){
    IOS;
    int t,k;
    cin >> t >> k;
    int count =0;
    for(int i=0; i<t; i++){
        int a;
        cin >> a;
        if(a<=k/2){
            count+=(a*2);
        }else{
            count += (k-a)*2;
        }
    }
    cout << count <<endl;

}