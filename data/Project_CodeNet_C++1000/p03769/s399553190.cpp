#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define M 105
using namespace std;

long long n;
vector<int>ans1;
int a[M];
int p=0;

void build(long long n){
    if (n==1)
        return;
    if (n%2==1) {
        a[++p]=1;
        build((n-1)/2);
    }
    else{
        a[++p]=2;
        build(n-1);
    }
        
}


int main() {
    cin >> n;
    int times=1;
    build(n);
    ans1.push_back(1);
    for (int i=p; i>=1; i--) {
        if (a[i]==1) {
            ans1.push_back(++times);
        }
        else{
            ans1.insert(ans1.begin(), ++times);
        }
    }
    cout << 2*(ans1.size()) << endl;
    for (int j=0; j<ans1.size(); j++) {
        cout << ans1[j] << " ";
    }
    for (int k=0; k<ans1.size(); k++) {
        if (k==ans1.size()-1)
            cout << k+1;
        else
            cout << k+1 << " ";
    }
    return 0;
}