#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,l,t;
    cin >> n >> l >> t;
    int arr[n],w[n];
    for (int i = 0; i < n; i++) cin >> arr[i] >> w[i];
    int finpos[n];
    for (int i = 0; i < n; i++){
        if (w[i] == 1) finpos[i] = (arr[i]+t)%l;
        else finpos[i] = (arr[i]+l-t%l)%l;
    }
    int start = 0;
    for (int i = 1; i < n; i++){
        if (w[i] != w[0]){
            int loop = t/l;
            int change = 2*loop;
            int timeleft = t-loop*l;
            if (w[0] == 1){
                int rem = arr[i]-arr[0];
                if (rem/2 < timeleft) change++;
                if ((rem+l)/2 < timeleft) change++;
                start = (start+change%n)%n;
            }
            else{
                int rem = l-arr[i]+arr[0];
                if (rem/2 < timeleft) change++;
                if ((rem+l)/2 < timeleft) change++;
                start = (start+n-change%n)%n;
            }

        }
    }
    int actpos[n];
    actpos[start] = finpos[0];
    sort(finpos,finpos+n);
    int newpos = 0;
    for (int i = 0; i < n; i++){
        if (finpos[i] == actpos[start]) {
            if (w[0] == 1)newpos = i;
            else if (i != n-1 && finpos[i+1] == actpos[start]) newpos = i+1;
            else newpos = i;
            break;
        }
    }
    for (int i = 1; i < n; i++) actpos[(start+i)%n] = finpos[(newpos+i)%n];
    for (int i = 0; i < n; i++) cout << actpos[i] << "\n";
}

