#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef priority_queue<int, vector<int>, greater<int> > PQ;

signed main(){
    int w, h;
    cin >> w >> h;

    PQ yoko, tate;
    int a;
    for(int i = 0;i < w;i++){
        cin >> a;
        yoko.push(a);
    }

    for(int i = 0;i < h;i++){
        cin >> a;
        tate.push(a);
    }

    int ans = 0;
    h++;
    w++;
    while(!tate.empty() || !yoko.empty()){
        if(tate.empty()){
            ans += yoko.top() * h;
            w = max(w-1, 0ll);
            yoko.pop();
        }else if(yoko.empty()){
            ans += tate.top() * w;
            h = max(h-1, 0ll);
            tate.pop();
        }else{
            if(tate.top() < yoko.top()){
                ans += tate.top() * w;
                h = max(h-1, 0ll);
                tate.pop();
            }else{
                ans += yoko.top() * h;
                w = max(w-1, 0ll);
                yoko.pop();
            }
        }
    }

    cout << ans << endl;

    return 0;
}
