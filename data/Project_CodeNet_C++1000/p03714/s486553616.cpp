#include<bits/stdc++.h>
using namespace std;

int main(){
    size_t N;
    cin >> N;
    vector<unsigned long> A(3 * N);
    for(auto& i : A)cin >> i;
    
    vector<long> ans(N + 1);
    {
        vector<unsigned long> B, C;
        {
            unsigned long sum{accumulate(A.cbegin(), A.cbegin() + N, 0UL)};
            priority_queue<unsigned long, vector<unsigned long>, greater<>> pq(A.cbegin(), A.cbegin() + N);
            B.push_back(sum);
            transform(A.cbegin() + N, A.cbegin() + 2 * N, back_inserter(B), [&sum, &pq](auto a){
                sum += a;
                pq.push(a);
                sum -= pq.top();
                pq.pop();
                return sum;
            });
        }
        {
            unsigned long sum{accumulate(A.crbegin(), A.crbegin() + N, 0UL)};
            priority_queue<unsigned long, vector<unsigned long>, less<>> pq(A.crbegin(), A.crbegin() + N);
            C.push_back(sum);
            transform(A.crbegin() + N, A.crbegin() + 2 * N, back_inserter(C), [&sum, &pq](auto a){
                sum += a;
                pq.push(a);
                sum -= pq.top();
                pq.pop();
                return sum;
            });
        }
        transform(B.cbegin(), B.cend(), C.crbegin(), ans.begin(), minus<long>());
    }
    cout << *max_element(ans.cbegin(), ans.cend()) << endl;
    return 0;
}