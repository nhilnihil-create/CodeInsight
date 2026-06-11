#include <iostream>
#include <vector>

using namespace std;

bool CanDefeat(const vector<int> &hp, int big_attack,
               int small_attack, int moves)
{
    auto attack_diff = big_attack - small_attack;
    auto needed = 0;

    for (const auto &elem : hp) {
        auto wanted = (elem - 1LL * small_attack * moves);
        wanted = (wanted + attack_diff - 1) / attack_diff;

        needed += max<long long int>(wanted, 0);
        if (needed > moves) {
            return false;
        }
    }
    return needed <= moves;
}

int Solve(const vector<int> &hp, int big_attack, int small_attack)
{
    auto moves = 0;
    auto power = (1 << 30);

    while (power > 0) {
        auto new_moves = moves + power;
        power >>= 1;

        if (!CanDefeat(hp, big_attack, small_attack, new_moves)) {
            moves = new_moves;
        }
    }
    return moves + 1;
}

int main()
{
    int monsters;
    cin >> monsters;

    int big_attack, small_attack;
    cin >> big_attack >> small_attack;

    vector<int> hp(monsters);
    for (auto &elem : hp) {
        cin >> elem;
    }

    auto res = Solve(hp, big_attack, small_attack);
    cout << res << "\n";

    return 0;
}
