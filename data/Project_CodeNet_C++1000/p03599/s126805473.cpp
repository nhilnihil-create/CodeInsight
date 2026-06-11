#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    double r = 0;
    double weight = a * 100;
    double sugar = 0;
    for(int w = 1; w <= f/100; w++){
        bool valid = false;
        for(int B = 0; B * b <= w; B++){
            if((w - B * b) % a == 0)valid = true;
        }
        if(!valid)continue;

        for(int s = 0; s <= e * w; s++){
            if(w * 100 + s > f)break;
            if(s*(100+e) > e*(100*w+s))break;
            bool val = false;
            for(int D = 0; D * d <= s; D++){
                if((s - D * d) % c == 0)val = true;
            }
            if(!val)continue;

            if(r <= 100.0*s/(100*w+s)){
                r = 100.0*s/(100*w+s);
                weight = 100*w + s;
                sugar = s;
            }
        }
    }
    cout << weight << ' ' << sugar << endl;
}