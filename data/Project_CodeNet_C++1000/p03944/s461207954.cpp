#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int w,h,n;
    cin >> w >> h >> n;
    vector<int> x(n),y(n),a(n);
    for(int i=0; i<n; i++){
        cin >> x.at(i) >> y.at(i) >> a.at(i);
    }

    int a1=0,a2=w,a3=0,a4=h;
    for(int i=0; i<n; i++){
        if(a.at(i)==1) a1=max(a1,x.at(i));
        else if(a.at(i)==2) a2=min(a2,x.at(i));
        else if(a.at(i)==3) a3=max(a3,y.at(i));
        else if(a.at(i)==4) a4=min(a4,y.at(i));
    }
    if(a2-a1>=0 && a4-a3>=0) cout << (a2-a1)*(a4-a3) << endl;
    else cout << 0 << endl;
}