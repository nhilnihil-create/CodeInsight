#include<bits/stdc++.h>

using namespace std;

class Solve {
    private:
    void merge(string *s, int l, int mid, int r) {
        int rl = r-mid;
        int ll = mid-l+1;
        string rs[rl], ls[ll];
        for(int i = 0; i < rl; i++) {
            rs[i] = s[mid+i+1];
        }
        for(int i = 0; i < ll; i++) {
            ls[i] = s[l+i];
        }
        int ir = 0, il = 0, k = l;
        while(ir < rl && il < ll) {
            if(rs[ir] <= ls[il]) {
                s[k++] = rs[ir];
                ir++;
            } else {
                s[k++] = ls[il];
                il++; 
            }
        }
        while(ir < rl) {
            s[k++] = rs[ir++];
        }
        while(il < ll) {
            s[k++] = ls[il++];
        }
    }
    void sortString(string *s, int l, int r) {
        if(l < r) {
            int mid = (l+r)/2;
            sortString(s, l, mid);
            sortString(s, mid+1, r);
            merge(s, l, mid, r);
        }
    }
    void solve(string *s, int len) {
        sortString(s,0,len-1);
        for(int i = 0; i < len; i++) {
            cout<<s[i];
        }
        cout<<endl;
    }
    public:
    void takeInput() {
        int n, l;
        cin>>n>>l;
        string s[n];
        for(int i = 0; i < n; i++) {
            cin>>s[i];
        }
        solve(s, n);
    }
};

int main() {
    Solve s;
    s.takeInput();
    return 0;
}