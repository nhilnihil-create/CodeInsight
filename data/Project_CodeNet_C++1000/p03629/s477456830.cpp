#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, char> i_c;
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;

int f(char moji){
    return (int)moji - (int)'a';
}
int mp[200500][30];
int main() {
    //cout.precision(10);
    string a;
    cin >> a;
    a = "S" + a + "G";
    int n = a.size();
    unordered_map<char, int> last;
    for(char moji = 'a'; moji <= 'z'; moji++){
        last[moji] = n + 1;
    }
    for(int i = n; i >= 0; i--){
        for(char moji = 'a'; moji <= 'z'; moji++){
            mp[i][f(moji)] = last[moji];
        }
        last[a[i]] = i;
    }
    unordered_map<int, char> shortest;
    unordered_map<int, int> length;
    length[n + 1] = 0;
    for(int i = n; i >= 0; i--){
        shortest[i] = 'a';
        length[i] = length[mp[i][f('a')]];
        for(char moji = 'b'; moji <= 'z'; moji++){
            if(length[mp[i][f(moji)]] < length[i]){
                shortest[i] = moji;
                length[i] = length[mp[i][f(moji)]];
            }
        }
        length[i]++;
        //cout << i << " " << shortest[i] << " " << length[i] << endl;
    }
    //cout << shortest[0] << " " << length[0] << endl;
    int index = 0;
    for(int i = 0; i < length[0]; i++){
        cout << shortest[index];
        index = mp[index][f(shortest[index])];
        //cout << index << endl;
    }
    cout << endl;
    return 0;
}