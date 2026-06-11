#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string makeString(long long x, long long y) {
    return to_string(x) + " " + to_string(y);
}

int main() {
    long long h,w,n;
    cin >> h >> w >> n;
    long long x,y;
    unordered_map<string, long long> m;
    for(long long i=0; i<n;i++){
        cin >> x >> y;
        for(int j=0; j<3; j++){
            if(x-j < 1 || x-j > h-2)
                continue;
            for(int k=0;k<3;k++){
                if(y-k < 1 || y-k > w-2)
                    continue;
                string s = makeString(x-j,y-k);
                if(m.find(s) == m.end()) {
                    m[s] = 1;
                }else {
                    m[s]++;
                }
            }
        }
    }
    vector<long long> v;
    for(int i=0;i<9;i++){
        v.push_back(0);
    }
    for(auto it = m.begin(); it != m.end(); it++){
        // cout << it->first << endl;
        v[it->second-1]++;
    }
    long long sum = (h-2)*(w-2);
    for(int i=0;i<9;i++){
        sum -= v[i];
    }
    cout << sum << endl;
    for(int i=0;i<9;i++){
        cout << v[i] << endl;
    }

}
