#include<bits/stdc++.h>

int main(){
    using namespace std;
    size_t N;
    cin >> N;
    deque<pair<size_t, size_t>> bef, aft;
    vector<size_t> ans(N * N), a(N);
    for(size_t i = 0, A; i < N;){
        cin >> A;
        if(i)for(size_t j = 0; j < i; ++j)bef.emplace_back(A, i + 1);
        if(++i != N)for(size_t j = i; j < N; ++j)aft.emplace_back(N * N - A, i);
        ans[A - 1] = i;
    }
    sort(bef.begin(), bef.end());
    sort(aft.begin(), aft.end());
    size_t cnt{};
    auto f = [&bef, &cnt](auto& i){
        ++cnt;
        if(i)return;
        if(bef.empty())return;
        if(bef.front().first < cnt)return;
        i = bef.front().second;
        bef.pop_front();
    };
    for_each(ans.begin(), ans.end(), f);
    if(!bef.empty())return !puts("No");
    cnt = 0;
    swap(bef, aft);
    for_each(ans.rbegin(), ans.rend(), f);
    if(!bef.empty())return !puts("No");
    puts("Yes");
    copy(ans.cbegin(), ans.cend(), ostream_iterator<size_t>(cout, " "));
}