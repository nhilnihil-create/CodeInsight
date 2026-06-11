#include<bits/stdc++.h>

using namespace std;

#define endl "\n"
#define lln long long int
#define IOS ios::sync_with_stdio(0);cin.tie(0);

vector<int> hm(100003);

int main(){
    IOS;

    int n;
    cin >> n;
    for(int i=0,val;i<n;i++){
        cin >> val;
        if(val-1<0) hm[100002]++;
        else hm[val - 1]++;
        hm[val+1]++;
        hm[val]++;
    }
    int ma = 0;
    for(int i=0;i<100003;i++){
        ma = max(ma,hm[i]);
    }
    cout << ma << endl;
    return 0;
}