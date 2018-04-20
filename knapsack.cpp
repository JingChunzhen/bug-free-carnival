#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Knapsack
{
  public:
    int target_sum_01(vector<int> a, int target);
    int target_sum_complete(vector<int> a, int target);
    int target_sum_01_fewest(vector<int> a, int target);
    int target_sum_complete_fewest(vector<int> a, int target);

  private:
};

/// 求加和等于target的a的子序列的个数, 要求数组a中的每一个数字仅可以取一次
int Knapsack::target_sum_01(vector<int> a, int target)
{
    vector<int> dp(target + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = target; j >= a[i]; j--)
        {
            if (dp[j - a[i]] != 0)
                dp[j] += dp[j - a[i]];
            else
                dp[j] = dp[j];
        }

        for (int j = 0; j < dp.size(); j++)
            cout << dp[j] << " ";
        cout << endl;
    }
    return dp[target];
}

/// 求加和等于target的a的序列的个数, 数组中的每一个数字可以取多次
int Knapsack::target_sum_complete(vector<int> a, int target)
{
    vector<int> dp(target + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = a[i]; j <= target; j++)
        {
            dp[j] += dp[j - a[i]];
        }
        for (int j = 0; j < dp.size(); j++)
            cout << dp[j] << " ";
        cout << endl;
    }

    return dp[target];
}

/// 求加和等于target的a的子序列中，长度最短的序列的长度, 要求数组a中的每一个数字仅可以取一次
int Knapsack::target_sum_01_fewest(vector<int> a, int target)
{
    vector<int> dp(target + 1, 0);

    for (int i = 0; i < a.size(); i++)
    {
        for (int j = target; j >= a[i]; j--)
        {
            if (dp[j - a[i]] != 0 && dp[j] != 0)
                dp[j] = min(dp[j - a[i]] + 1, dp[j]);
            else if (dp[j - a[i]] != 0 && dp[j] == 0)
                dp[j] = dp[j - a[i]] + 1;
            else if (j == a[i])
                dp[j] = 1;
        }

        for (int j = 0; j <= target; j++)
            cout << dp[j] << " ";
        cout << endl;
    }

    return dp[target];
}

/// 求加和等于target的a的序列中，长度最短的序列的长度, 数组中的每一个数字可以取多次
int Knapsack::target_sum_complete_fewest(vector<int> a, int target)
{
    // still dp
    vector<int> dp(target + 1, 0);
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = a[i]; j <= target; j++)
        {
            if (j == a[i])
                dp[a[i]] = 1;
            else if (dp[j] == 0)
                dp[j] = dp[j - a[i]] + 1;
            else
                dp[j] = min(dp[j], dp[j - a[i]] + 1);
        }

        for (int j = 0; j < dp.size(); j++)
            cout << dp[j] << " ";
        cout << endl;
    }

    return dp[target];
}

int main()
{

    Knapsack *ks = new Knapsack();

    //  int ta[] = {2, 1, 4, 5, 3};
    int ta[] = {1, 2, 3, 4, 5};
    vector<int> a(ta, ta + 5);
    // int res = ks->target_sum_01(a, 7);
    // cout << res << endl;
    // ks->target_sum_complete();

    // int res = ks->target_sum_complete(a, 7);
    // cout << res << endl;

    int res = ks->target_sum_01_fewest(a, 7);
    cout << res << endl;

    return 0;
}