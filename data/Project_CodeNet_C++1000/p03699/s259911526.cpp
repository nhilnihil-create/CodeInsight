#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> pts(n);
    for (int i = 0; i < n; i++){
      cin >> pts.at(i);
    }

    bool ten=true;

    for (int i = 0; i < n; i++){
      if(pts.at(i)%10!=0){
          ten=false;
      }
    }

    if(ten){
        cout << 0 << endl;
        exit(0);
    }
    
    sort(pts.begin(),pts.end());
    int ptssum=accumulate(pts.begin(),pts.end(),0);

    int scr=ptssum;
    if(scr%10==0){
        for (int i = 0; i < n; i++){
            scr=ptssum-pts.at(i);
            if(scr%10!=0){
                break;
            }
        }
    }
    

    cout << scr << endl;
    
}