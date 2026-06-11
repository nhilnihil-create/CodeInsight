#define _USE_MATH_DEFINES
#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <complex>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <limits>
#include <climits>
#include <cfloat>
#include <functional>
#include <iterator>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int> > v(n, vector<int>(n));
    long long sum = 0;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cin >> v[i][j];
            sum += v[i][j];
        }
    }
    sum /= 2;

    for(int a=0; a<n; ++a){
        for(int b=0; b<a; ++b){
            bool isRemove = false;
            for(int c=0; c<n; ++c){
                if(a == c || b == c)
                    continue;
                if(v[a][c] + v[c][b] < v[a][b]){
                    cout << -1 << endl;
                    return 0;
                }
                else if(!isRemove && v[a][c] + v[c][b] == v[a][b]){
                    sum -= v[a][b];
                    isRemove = true;
                }
            }
        }
    }
    cout << sum << endl;

    return 0;
}
