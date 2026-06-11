#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int main() {
    string s; cin >> s;
    int n = s.size();
    for(int left=0;left<n;left++) {
        int right = left;
        map<char, int> mp;
        while(right < n && right-left <=2) {
            mp[s[right]] = 1;
            if(right-left==1 && mp.size()==1) {
                printf("%d %d\n", left+1, right+1);
                return 0;
            }
            if(right-left==2 && mp.size()==2) {
                printf("%d %d\n", left+1, right+1);
                return 0;
            }
            right++;
        }
    }
    printf("%d %d\n", -1, -1);
}
