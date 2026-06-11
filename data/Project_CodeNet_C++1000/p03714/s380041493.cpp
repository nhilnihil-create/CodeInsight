#include<iostream>
#include<string>
#include<algorithm>
#include<queue>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
#define P pair<long int, long int> 

int main(){
    int n;
    cin >> n;
    long int a[3*n];
    rep(i, 3 * n) cin >> a[i];
    priority_queue<P, vector<P>, greater<P> > q1;
    priority_queue<P> q2;
    priority_queue<P, vector<P>, greater<P> > q3;
    long int c[3*n];
    fill(c, c + 3 * n, 1);
    long int sm1 = 0, sm2 = 0;
    for (int i = 0; i < n; i++){
        q1.push(P(a[i], i));
        sm1 += a[i];
    }
    for (int i = n; i < 3 * n; i++){
        q2.push(P(a[i], i));
        sm2 += a[i];
    }
    for (int i = 0; i < n; i++){
        P p = q2.top();
        q2.pop();
        sm2 -= p.first;
        c[p.second] = 0;
        q3.push(p);
    }
    long int ans = sm1 - sm2;
    for (int i = n; i < 2 * n; i++){

        // rep(i, 3 * n) cout << c[i] << " ";
        // cout << endl;
        // cout << ans << endl;
        if (c[i] == 1){
            sm2 -= a[i];
            P p2 = q3.top();
            q3.pop();
            while(p2.second <= i){
                p2 = q3.top();
                q3.pop();
            }
            sm2 += p2.first;
            c[p2.second] = 1;
        }
        q1.push(P(a[i], i));
        sm1 += a[i];
        c[i] = 1;
        P p1 = q1.top();
        q1.pop();
        sm1 -= p1.first;
        c[p1.second] = 0;
        ans = max(ans, sm1 - sm2);


        
    }

    // rep(i, 3 * n) cout << c[i] << " ";
    // cout << endl;
    cout << ans << endl;


    
    
}