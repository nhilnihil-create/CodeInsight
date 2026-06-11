#include<bits/stdc++.h>

using namespace std;

#define LL long long
#define DD double
#define Pb push_back
#define Bp pop_back
#define Pf push_front
#define Fp pop_front
#define Ub upper_bound
#define Lb lower_bound
#define In insert
#define All(x) x.begin(), x.end()
#define mem(a, b) memset(a, b, sizeof(a))
#define fast ios_base::sync_with_stdio(0);cin.tie(0)
#define X first
#define Y second
#define mx1 10
#define mx2 110
#define mx3 1010
#define mx4 10010
#define mx5 100010
#define mx6 1000010

typedef vector<LL> Vl;
typedef vector<DD> Vd;
typedef vector<bool> Vb;
typedef vector<Vl> VVl;
typedef pair<LL, LL> Pll;
typedef pair<DD, DD> Pdd;
typedef vector<Pll> Vpl;
typedef vector<Pdd> Vpd;
typedef queue<LL> Ql;
typedef stack<LL> Sl;
typedef deque<LL> Dl;

LL _set(LL N, LL pos) {return N = N | (1 << pos);}
LL _reset(LL N, LL pos) {return N = N & ~(1 << pos);}
bool _check(LL N, LL pos) {return (bool)(N & (1 << pos));}
bool _upper(char a) {return a >= 'A' && a <= 'Z';}
bool _lower(char a) {return a >= 'a' && a <= 'z';}
bool _digit(char a) {return a >= '0' && a <= '9';}

LL dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
LL dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

///**************************DONE****************************///

int main()
{
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;


    vector<int> A, B;

    for(int i = 0; i <= 300; i++){
        for(int j = 0; j <= 300; j++)
            if(100 * a * i + 100 * b * j <= f && 100 * a * i + 100 * b * j > 0)
                A.Pb(100 * a * i + 100 * b * j);
    }

    for(int i = 0; i <= 3000; i++){
        for(int j = 0; j <= 3000; j++)
            if(c * i + d * j <= f)
                B.Pb(c * i + d * j);
    }

    int la = A.size(), lb = B.size();

    int I = 0, J = 0;
    DD ans = 0.;
    for(int i = 0; i < la; i++){
        for(int j = 0; j < lb; j++){
            if(A[i] + B[j] <= f){
                DD x = (100. * B[j]) / (DD)A[i];
                if(x > (DD)e)
                    continue;

                if(x > ans)
                    ans = x, I = i, J = j;
            }
        }
    }

    cout << A[I] + B[J] << ' ' << B[J] << '\n';
    return 0;
}
