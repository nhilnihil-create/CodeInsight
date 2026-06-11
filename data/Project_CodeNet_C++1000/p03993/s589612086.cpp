#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main(){
    int n;
    cin >> n;
    pair<int,int> usagi[n];

    for(int i=0; i<n;i++){
        int a;
        cin >> a;
        a--;
        usagi[i] = make_pair(i,a);
    }

    int k(0);
    for(int i=0; i<n; i++){
        int t = usagi[i].second;
        if(usagi[t].second == i){
            k++;
            usagi[i].second = -1;
        }
    }
    cout << k << endl;
}
