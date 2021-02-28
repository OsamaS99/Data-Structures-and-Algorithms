#include <iostream>
#include <vector>
#include <climits>

#define COINS 3

using std::vector;
vector<int> coins = { 1 , 3 , 4 };

int get_change(int m)
{

    std::vector<int> coins_num(m + 1);

    coins_num[0] = 0;

    for (int i = 1; i <= m; ++i)
        coins_num[i] = INT_MAX;

    for (int i = 1; i <= m; ++i)
    {
        for (int j = 0; j < COINS; ++j)
        {
            if (coins[j] <= i)
            {
                int alternative = coins_num[i - coins[j]];
                if (sub_res != INT_MAX && alternative + 1 < coins_num[i])
                    coins_num[i] = alternative + 1;
            }
        }
    }
    return coins_num[m];
}

int main()
{
    int m;
    std::cin >> m;
    std::cout << get_change(m) << '\n';
}