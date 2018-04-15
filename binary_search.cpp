#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class BS
{
  public:
    int upper_bound(vector<int> a, int target);
    int lower_bound(vector<int> a, int target);
    int binary_search(vector<int> a, int target);
    int binary_search_recursive(vector<int> a, int target, int start, int end);

  private:
};

int BS::upper_bound(vector<int> a, int target)
{
    int start = 0;
    int end = a.size();
    // 半开半闭区间
    int res;
    while (start < end)
    {
        int mid = start + (end - start) / 2;
        // 防止溢出
        if (a[mid] == target)
        {
            if (mid + 1 < end && a[mid + 1] == target)
                start = mid + 1;
            else
            {
                res = mid;
                break;
            }
        }
        else if (a[mid] < target)
            start = mid + 1;
        else
            end = mid;
    } // end of while

    return res;
}

int BS::lower_bound(vector<int> a, int target)
{
    int start = 0;
    int end = a.size();
    int res;
    while (start < end)
    {
        int mid = start + (end - start) / 2;
        if (a[mid] == target)
        {
            if (mid - 1 >= start && a[mid - 1] == target)
                end = mid;
            else
            {
                res = mid;
                break;
            }
        }
        else if (a[mid] < target)
            start = mid + 1;
        else
            end = mid;
    } // end of while

    return res;
}

int BS::binary_search(vector<int> a, int target)
{
    int start = 0;
    int end = a.size();
    int res;
    while (start < end)
    {
        int mid = start + (end - start) / 2;
        if (a[mid] == target)
        {
            res = mid;
            break;
        }
        else if (a[mid] < target)
            start = mid + 1;
        else
            end = mid;
    } // end of while

    return res;
}

int BS::binary_search_recursive(const vector<int> a, const int target, int start, int end)
{
    if (start < end)
    {
        int mid = start + (end - start) / 2;
        if (a[mid] == target)
            return mid;
        else if (a[mid] < target)
            return binary_search_recursive(a, target, start, mid);
        else
            return binary_search_recursive(a, target, mid + 1, end);
    } // end of if
    else
        return 0;
}

int test_BS()
{
    int ta[] = {3, 3, 4, 4, 8, 9, 12, 15, 17, 18, 63, 74, 86, 92, 103, 105};
    vector<int> a(ta, ta + 16);

    BS *bs = new BS();
    int res;
    res = bs->upper_bound(a, 3); // 1
    cout << res << endl;
    res = bs->lower_bound(a, 4); // 2
    cout << res << endl;
    res = bs->binary_search(a, 15); // 7
    cout << res << endl;

    res = bs->binary_search_recursive(a, 15, 0, 16);
    cout << res << endl;
}

int main()
{
    test_BS();
}