#include <bits/stdc++.h>
#include <vector>
#include <cmath>
using namespace std;
 
int main() {
    int h,w;
    cin >> h >> w;
    
    for(int i=0 ; i < w+1 ; i++){//一番上の#
        cout << "#" ;
    }
    cout << "#" << endl;
    for (int j = 0; j < h; j++)
    {
    vector<string> vec(h);
    cin >> vec[j];
    cout << "#" << vec[j] << "#" << endl;
    }
    for(int i=0 ; i < w+1 ; i++){//一番下の#
        cout << "#" ;
    } 
    cout << "#"<< endl;
}