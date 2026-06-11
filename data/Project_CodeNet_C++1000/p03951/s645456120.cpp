#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;  cin >> n;
    string a, b;    cin >> a >> b;
    
    int cnt=2*n;
    for(int i=0; i<n; i++){
        string s1 = a.substr(i);
        string s2 = b.substr(0, n-i);
        if(s1!=s2)  continue;
        cnt = 2*i+(n-i);
        break;
    }
    
    cout << cnt << endl;

}
