#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n, sum=0, mi=1000;
    cin >> n;
    vector<int>s(n);
    for(int i=0; i<n; i++){
        cin >> s[i];
        sum += s[i];
        if(s[i]%10!=0) mi = min(mi,s[i]);
    }
    if(sum%10==0){
        if(mi==1000) cout << 0 << endl;
        else cout << sum - mi << endl;
    }else{
        cout << sum << endl;
    }
    return 0;
}