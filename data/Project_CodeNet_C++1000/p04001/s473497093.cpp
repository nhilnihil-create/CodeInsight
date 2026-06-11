#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i < (n); i++)
using namespace std;
using ll = long long;

int ctoi(const char c){
  if('0' <= c && c <= '9') return (c-'0');
  return -1;
}

int main(){
    string s;
    cin >> s;
    //int size = s.size();
    ll ans=0;
    
    for(int tmp=0; tmp < (1 << (s.size() -1)); tmp++){
        //cout << tmp << endl;
        bitset<10> bit(tmp);
        ll sum = 0;
        ll ret = ctoi(s[0]);
        for(int i=0; i< s.size() -1 ; i++){
            if(bit.test(i)){
                sum += ret;
                ret = ctoi(s[i+1]);
            }else{
                ret *=10;
                ret += ctoi(s[i+1]);
                
            }
            //cout << sum << endl;
            //cout << ret << endl;
            
        }
        if(ret != 0){
                sum += ret;
        }
        //cout << sum << endl;
        ans += sum;
    }
    
    cout << ans << endl;
}
