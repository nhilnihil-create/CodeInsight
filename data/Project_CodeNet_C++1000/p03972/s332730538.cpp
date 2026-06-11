#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
int main(void){
    long long w, h;
    cin >> w >> h;
    vector<long long> p(w);
    for(long long i=0; i<w; i++){
        cin >> p[i];
    }
    vector<long long> q(h);
    for(long long i=0; i<h; i++){
        cin >> q[i];
    }
    long long ans = 0;
    long long count = 0;
    sort(p.begin(), p.end());
    sort(q.begin(), q.end());
    int pi=0, qi=0;
    int nxt = 0;
    int val = 0;
    long long a = w+1;
    long long b = h+1;
    while(count<h*w+h+w){
        nxt = 0;
        if(pi==w){
            nxt = 2;
        }
        if(qi==h){
            nxt = 1;
        }
        if(nxt==0){
            if(p[pi]<q[qi]){
                nxt = 1;
            }else{
                nxt = 2;
            }
        }
        if(nxt==1){
            val = min(h*w+h+w-count, b);
            count += val;
            ans += val*p[pi];
            pi += 1;
            a -= 1;
        }else{
            val = min(h*w+h+w-count, a);
            count += val;
            ans += val*q[qi];
            qi += 1;
            b -= 1;
        }
        //cout << nxt << " val=" << val << " count=" << count << " ans=" << ans << endl;
    }
    cout << ans << endl;
}