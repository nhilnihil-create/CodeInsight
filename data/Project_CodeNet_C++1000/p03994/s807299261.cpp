#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#include<map>
#include<string>
#define all(x) (x).begin(),(x).end()
typedef long long ll;
 
using namespace std;

int main(){
    string s;   cin >> s;
    int K;  cin >> K;
    int i, j, k, l, nmax, tmp;
    l = s.length();
    vector<int> v(l);
    nmax = min(K, l*25);
    for(int i=0; i<l; i++){
        char c = s[i];
        int x = (26 - (c - 'a'))%26;
        v[i] = x;
    }
    i = 0;
    j = 0;
    tmp = K;
    while(i < K){
        if(v[j] <= tmp){
            s[j] = 'a';
            i += v[j];
            j++;
        }else{
            for(int k=j+1; k<l; k++){
                if(v[k] <= tmp){
                    s[k] = 'a';
                    tmp -= v[k];
                }
            }
            char c = s[l-1];
            c = c + tmp;
            s[l-1] = c;
            break;
        }
        tmp = K-i;
        if(j==l){
            char c = s[l-1];
            tmp %= 26;
            c += tmp;
            s[l-1] = c;
            break;
        }
    }
    cout << s << endl;
    return 0;
}