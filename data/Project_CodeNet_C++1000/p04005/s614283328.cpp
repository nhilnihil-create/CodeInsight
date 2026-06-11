#include <bits/stdc++.h>
using namespace std;
 
int main() {
    vector<long long>vec(3);
    for(int i=0;i<3;i++){
        cin>>vec.at(i);
    }
    sort(vec.begin(),vec.end());
    if(vec.at(0)%2==1&&vec.at(1)%2==1&&vec.at(2)%2==1){
        cout<<vec.at(0)*vec.at(1)<<endl;
        return 0;
    }

    cout <<0<<endl;
}