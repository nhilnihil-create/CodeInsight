#include <bits/stdc++.h>
using namespace std;

//考え方が大事
// とりあえず、関係ない、小さいほうのやつらN人を、各チームにふりわける。
// 残りの2N人をどうするか、という段階になれば、AGC001-Aと同じ問題になる。
// で、N+1番目に小さいものとどれがペアを組めばいいかというと、N+2番目と組めばいいのであって、
// その流れで、N+3は、N+4と組めばいい。これを最後まで続けていけばいい。

int N;
int a[300010];

int main(){
    cin>>N;

    for (int i = 0; i < 3*N; i++)
    {
        cin>>a[i];
    }
    
    sort(a, a+3*N);
    

    long long ans = 0;
    for (int i = N; i < 3*N-1; i+=2)
    {
        ans += a[i];
    }
    
    cout << ans << endl;
    return 0;
}
