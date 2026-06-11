#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <math.h>
#include <algorithm>
#include <deque>
#include <climits>

using namespace std;
#define ll long long
#define ve vector
#define umap unordered_map

const int MxN=105;
char a[MxN];

int main() {
    int h,w;
    cin>>h>>w;
    for(int i=0;i<h;i++) {
        for(int j=0;j<w;j++) {
            cin>>a[j];
            cout<<a[j];
        }
        cout<<endl;
        for(int j=0;j<w;j++) {
            cout<<a[j];
        }
        cout<<endl;
    }
    return 0;
}