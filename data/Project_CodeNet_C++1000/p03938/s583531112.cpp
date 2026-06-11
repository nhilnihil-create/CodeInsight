#include <bits/stdc++.h>
using namespace std;

template <class T>
struct BIT {
    vector<T> lst;
    int treesize;
    // constructor
    BIT(int newn = 0) {
        treesize = newn;
        lst.resize(treesize + 1);
        for(int i = 0; i <= treesize; ++i) lst[i] = 0;
    }
    // a_place += num
    bool add(int place, T num) {
        while(place <= treesize) {
            lst[place] += num;
            place += place & -place;
        }
        return 1;
    }
    // add wide ver.(add num between l and r)
    bool addw(int left, int right, T num) {
        while(left <= right && left >= 1 && right <= treesize)
            add(left++, num);
        return 1;
    }
    // sum between l and r
    T calcsum(int place) {
        T answer = 0;
        while(place > 0) {
            answer += lst[place];
            place -= place & -place;
        }
        return answer;
    }
    // sum between l and r(calcsum wide ver.)
    T calcsumw(int left, int right) {
        return calcsum(right) - calcsum(left - 1);
    }
};

BIT<long long> memo;
long long n;
vector<long long> a,b,p;

void solve();

int main(){
    cin >> n;
    a.resize(n,1);
    b.resize(n,1);
    p.resize(n);
    memo = BIT<long long>(n);
    for(int i = 0;i < n;++i)cin >> p[i];
    solve();
    for(int i = 0;i < n;++i){
        if(i != 0)cout << " ";
        cout << a[i];
    }
    cout << endl;
    for(int i = 0;i < n;++i){
        if(i != 0)cout << " ";
        cout << b[i];
    }
    cout << endl;
    return 0;
}

void solve(){
    for(int i = 1;i < n;++i){
        a[i] = a[i-1] + 1;
        b[n-1-i] = b[n-i] + 1;
    }
    for(int i = 0;i < n;++i){
        long long now = p[n - 1 - i];
        memo.add(now,i);
    }
    for(int i = 0;i < n;++i){
        a[i] += memo.calcsum(i);
        b[i] += memo.calcsumw(i+2,n);
    }
}