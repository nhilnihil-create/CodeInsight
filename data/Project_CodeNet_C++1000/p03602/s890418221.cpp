//
// Created by kapildd on 10/5/17.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector< vector<int> > dist(n, vector<int>(n));
    vector< vector<int> > adj(n, vector<int>(n, 0));
    vector< vector<int> > dist2(n, vector<int>(n, INT_MAX));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin>>dist[i][j];
            adj[i][j] = dist2[i][j] = dist[i][j];
        }
    }
    for(int k=0; k<n; k++) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    int poss = 1;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(dist[i][j] != dist2[i][j]) {
                poss = 0;
            }
        }
    }
    if(!poss) {
        cout << -1 << endl;
        return 0;
    }
    for(int k=0; k<n; k++) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(adj[i][k]==0 || adj[k][j]==0 || adj[i][j]==0) continue;
                if(adj[i][j] == adj[i][k] + adj[k][j]) {
                    adj[i][j] = 0;
                }
            }
        }
    }
    long long ans = 0;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            ans += adj[i][j];
        }
    }
    cout << ans << endl;
}