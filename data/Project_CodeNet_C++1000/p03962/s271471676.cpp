#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main(){
    vector<int> dta(3);
    int ans=0, save=0;
    for (int i=0; i<3; i++) cin>>dta[i];

    for (int i=1; i<3; i++){
        if (dta[0]==dta[i]) save++;
        if (save == 2) save--;
    }
    if (dta[1]==dta[2]) save++;
    ans = 3 - save;
    cout<<ans<<endl;
}
