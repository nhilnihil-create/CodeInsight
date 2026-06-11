#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<int> color(8);
    int over=0;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        if(a >= 3200) over++;
        else color.at(a/400)=1;
    }
    int tot=0;
    for(int i=0; i<8; i++){
        tot += color.at(i);
    }
    cout << max(1, tot) << " " << tot+over << endl;
}