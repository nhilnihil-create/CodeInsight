
#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
#define repi(i, n) for(auto i = (n).begin(); i != (n).end(); i++)
#define in_arr(type, a, n) copy_n(istream_iterator<type>(cin), n, (a).begin());
#define ll long long int

int main(){
    int h, w;
    cin >> h >> w;
    vector< vector<string> > s(h);
    repi(i, s){
        *i = vector<string>(w);
        repi(j, *i){
            cin >> *j;
        }
    }
    
    rep(i, h){
        rep(j, w){
            if(s[i][j] == "snuke"){
                cout << (char)(j + 'A') << i + 1 << endl;
                return 0;
            }
        }
    }
    return 0;
}
