#include <bits/stdc++.h>
#define int long long

#ifndef appmode
#define appmode	2
#endif

#define INDEX_MAX   55
#define CARD_MAX    55
#define SUM_MAX     2555

class CounterInterface
{
public:
    virtual int get(std::vector<int> Xj, int A) = 0;
};

/**
 * 3.1部分点解法
 * 部分点制約ではNが小さいので，すべてのカードの選び方(2N−1通り)を試すことができる．
 * 全通り試すにはビット演算を用いるのが楽である．
 * 具体的にはABC 014 B問題(http://abc014.contest.atcoder.jp/tasks/abc014_2)などを参照するとよい．
 * 計算量は全体でO(N·2N)となる
 */
class Counter31 : public CounterInterface
{
public:
    static Counter31* factory()
    {
        return new Counter31();
    }
    virtual int get(std::vector<int> Xj, int A)
    {
        int P = 0;
        for (int b = 1; b < 2 << (Xj.size() - 1); b++)
        {
            double a = 0.0;
            int i = 0;
            for (auto itr = Xj.begin(); itr != Xj.end(); ++itr)
            {
                if (b & 1 << std::distance(Xj.begin(), itr))
                {
                    a += *itr;
                    i += 1;
                }
            }
            P += (A == a / i);
        }
        return P;
    }
};

/**
 * 3.2満点解法1
 * 以下の3次元配列dp[j][k][s](ただし0≤j≤N,0≤k≤N,0≤s≤NX)を考える．
 * dp[j][k][s]=(x1,...,xjからk枚選んでxiの合計をsにするような選び方の総数)この配列は次のように計算することができる．
 * dp[j][k][s]=⎧⎪⎪⎪⎨⎪⎪⎪⎩1(j=0,k=0,s=0のとき)dp[j−1][k][s](j≥1,s<xjのとき)dp[j−1][k][s]+dp[j−1][k−1][s−xj](j≥1,k≥1,s≥xjのとき)0(上記いずれでもないとき)さて，
 * 選んだカードのxiの平均をAにするには，各k(1≤k≤N)について，k枚選んだときの合計がkAであればよい．
 * すなわち∑Nk=1dp[N][k][kA]が答えとなる．
 * 動的計画法を用いるることで，計算量は全体でO(N3X)時間となる．
 */
class Counter32 : public CounterInterface
{
private:
    std::vector<int> Xj;
    int A;
    int dp[INDEX_MAX][CARD_MAX][SUM_MAX];

    int dp_search(int j, int k, int s)
    {
#if NDEBUG
        assert(0 <= j && j <= INDEX_MAX - 1);
        assert(0 <= k && k <= CARD_MAX - 1);
        assert(0 <= s && s <= SUM_MAX - 1);
#endif
        if (j >= this->Xj.size())
        {
            // 全部調べ終わる
            return ((k * this->A) == s) && (0 != s);
        }
        if (-1 != this->dp[j][k][s])
        {
            // 計算済み
            return this->dp[j][k][s];
        }
        int a = this->dp_search(j + 1, k + 1, s + this->Xj[j]);
        int b = this->dp_search(j + 1, k, s);
        return this->dp[j][k][s] = a + b;
    }
public:
    static Counter32* factory()
    {
        return new Counter32();
    }
    virtual int get(std::vector<int> Xj, int A)
    {
        this->Xj = Xj;
        this->A = A;
        memset(this->dp, -1, sizeof(this->dp));
        return this->dp_search(0, 0, 0);
    }
};

/**
 * 3.3満点解法2
 * 「選んだカードのxiの平均がA」であることは，「選んだカードの(xi−A)の合計が0」と言い換えることができる．
 * すなわち，各カードiについてyi=xi−Aと定義すると，選んだカードのyiの合計が0となるようなカードの選び方の総数を求めればよいことになり，選んだ枚数を考慮する必要がなくなる．
 * この考え方に基づく，O(N2X)時間の解法も存在する．
 * 実装においては，yiが負となりうることを考慮し，以下の2次元配列dp[j][t](ただし0≤j≤N,0≤t≤2NX)を考えるとよい．
 * dp[j][t]=(y1,...,yjから0枚以上選んでyiの合計をt−NXにするような選び方の総数)この配列は次のように計算することができる．
 * dp[j][t]=⎧⎪⎪⎪⎨⎪⎪⎪⎩1(j=0,t=NXのとき)dp[j−1][t](j≥1，かつ，t−yj<0またはt−yj>2NXのとき)dp[j−1][t]+dp[j−1][t−yj](j≥1,0≤t−yj≤2NXのとき)0(上記いずれでもないとき)1枚も選ばないパターンを除外する必要があるため，答えはdp[N][NX]−1となる．
 */
class Counter33 : public CounterInterface
{
private:
    std::vector<int> Xj;
    int A;
    int dp[INDEX_MAX][SUM_MAX];

    int dp_search(int j, int k, int s)
    {
#if NDEBUG
        assert(0 <= j && j <= INDEX_MAX - 1);
        assert(0 <= s && s <= SUM_MAX - 1);
#endif
        if (j >= this->Xj.size())
        {
            // 全部調べ終わる
            return (0 == (s - this->A * k));
        }
        if (-1 != this->dp[j][s])
        {
            // 計算済み
            return this->dp[j][s];
        }
        int a = this->dp_search(j + 1, k + 1, s + this->Xj[j]);
        int b = this->dp_search(j + 1, k, s);
        return this->dp[j][s] = a + b;
    }
public:
    static Counter33* factory()
    {
        return new Counter33();
    }
    virtual int get(std::vector<int> Xj, int A)
    {
        this->Xj = Xj;
        this->A = A;
        memset(this->dp, -1, sizeof(this->dp));
        return this->dp_search(0, 0, 0);
    }
};

signed main(void)
{
    int N, A;
    std::cin >> N >> A;

    std::vector<int> Xj(N);
    for (int i = 0; i < N; i++)
    {
        std::cin >> Xj[i];
    }

#if appmode == 1
    CounterInterface* counter = Counter31::factory();
#elif appmode == 2
    CounterInterface* counter = Counter32::factory();
#elif appmode == 3
    CounterInterface* counter = Counter33::factory();
#endif
    std::cout << counter->get(Xj, A) << std::endl;

    return 0;
}