 #include <bits/stdc++.h>
 using namespace std;
 #define rep(i,N) for(int i=0;i<int(N);++i)
 using ll = long long;

ll func(vector<int> plus,string s){
    ll now_sum=0;
    ll num=(int)(s[0]-'0');
    //plus +を置く場所に1、置かない場所に0
    for(int i=0;i<s.size()-1;i++){
        if(plus[i]==1) {
            now_sum+=num;
            num = 0;
            num += s[i+1]-'0';
        }
        else{
            num=10*num;
            num+=(int)(s[i+1]-'0');
        }
    }
    now_sum+=num;
    return now_sum;
}

int main() {
    string s;
    cin >> s;
    // n +の配置位置の数
    int n = s.size()-1;
    ll sum = 0;

    // bit 全探索
    for (int bit = 0; bit < (1 << n); ++bit) {
        vector<int> plus(n);
        for (int i = 0; i < n; ++i) {
            if (bit & (1 << i)) {
            plus[n-i-1]=1;
            }

        }
        //sを分解して和を取る関数
        sum += func(plus,s);
    }
    cout << sum << endl;
}