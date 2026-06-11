#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const long long INF = 1e15;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    string s;
    cin >> s;
    int k;
    cin >> k;

    int n = s.size();

    for(int i = 0; i < n; i++){
        if('z'-s[i] < k && s[i] != 'a'){
            k -= 'z'-s[i]+1;
            s[i] = 'a';
        }
        if(k > 0 && i == n-1){
            s[i] += k%26;
        }
    }

    cout << s << endl;
    return 0;
}