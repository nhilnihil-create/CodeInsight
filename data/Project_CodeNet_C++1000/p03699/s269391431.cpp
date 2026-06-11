#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    int minus=101;
    int tot=0;
    for(int i=0; i<n; i++){
        int s;
        cin >> s;
        tot += s;
        if(s%10!=0) minus=min(minus, s);
    }
    if(tot%10!=0) cout << tot << endl;
    else{
        if(minus==101) cout << 0 << endl;
        else cout << tot - minus << endl;
    }
}