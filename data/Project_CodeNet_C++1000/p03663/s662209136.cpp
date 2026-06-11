#include<bits/stdc++.h>
using namespace std;

long long query, ans, NUM;
char c;
bool isnine = true;

long long po(int k){
    long long x = 10, ans = 1;
    while (k){
        if (k&1) ans *= x;
        x = x * x;
        k >>= 1;
    }
    return ans;
}

bool ask(long long query){
    cout << "? " << query << "\n"; cout.flush();
    cin >> c;
    return c == 'Y';
}

void answer(long long x){
    cout << "! " << x << "\n";
}

int main(){
    for (int i = 10; i >= 0; i--){
        int l = (i == 10), r = 9;
        while (l != r){
            int mid = (l + r + 1) / 2;
            if (ask(query + mid * po(i+1))) r = mid-1;
            else l = mid;
        }
        if (r != 9){
            isnine = false;
            if (ask((query + (r+1) * po(i+1)) / po(i+1))) {
                if (ask((query + r * po(i+1)) / po(i))) answer((query + r * po(i+1)) / po(i+1));
                else answer((query + (r+1) * po(i+1)) / po(i+1));
            }
            else {
                ans *= 10;
                ans += r;
                query += r * po(i+1);
            }
        }
        else{
            if (ask((query + r * po(i+1)) / po(i+1) + 1) != isnine) {
                answer((query + r * po(i+1)) / po(i+1));
            }
            else {
                ans *= 10;
                ans += r;
                query += r * po(i+1);
            }
        }
    }
    answer(ans);
}