#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int n;
    cin >> n;
    string s,t;
    cin >> s >> t;
    int tan;
    tan=n;
    int i;
    i=0;
    while(i<=n){
        string z1,z2;
        for(int j=0;j<n-i;j++){
            z1+=s.at(i+j);
            z2+=t.at(j);
        }
        if(z1==z2)break;
        else tan--;
        i++;
    }
    cout << 2*n-tan << endl;
    return 0;
}