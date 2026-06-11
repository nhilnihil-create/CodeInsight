#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

int main(){
    int W,H;
    cin >> W >> H;
    vector<int> p(W,0);
    vector<int> q(H,0);
    for(int i=0; i<W; i++){
        cin >> p[i];
    }
    for(int i=0; i<H; i++){
        cin >> q[i];
    }
    sort(p.begin(),p.end());
    sort(q.begin(),q.end());
    p.push_back(1000000007);
    q.push_back(1000000007);

    int i=0;
    int j=0;
    int k=0;
    long long ans=0;
    while(i<W+H){
        if(p[j]<q[k]){
            ans+=(long long) p[j]*(H-k+1);
            //cout << p[j] << endl;
            j++;
        }else{
            ans+=(long long) q[k]*(W-j+1);
            //cout << q[k] << endl;
            k++;
        }
        i++;
    }
    cout << ans << endl;    
}