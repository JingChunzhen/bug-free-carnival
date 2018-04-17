#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Combinatorics
{
  public:
    // sample k numbers from a C_{a.size()}^{K}
    void sample(vector<int> a, int start, int k);
    void permutations(vector<int> &a, int begin);
    // get all subsets of vector a
    void subsets(vector<int> a, int cnt);
    void subsets_v2(vector<int> a, int cnt);
    void subsets_v3(vector<int> a, int cnt);
    // print private variable res
    void get_res();

  private:
    vector<vector<int> > res;
    vector<int> path;
};

void Combinatorics::sample(vector<int> a, int start, int k)
{
    if (k == 0)
        res.push_back(path);
    if (a.size() - start < k)
        return;
    for (int i = start; i < a.size(); i++)
    {
        path.push_back(a[i]);
        sample(a, i + 1, k - 1);
        path.pop_back();
    }
}

void Combinatorics::permutations(vector<int> &a, int begin)
{
    if (begin == a.size())
    {
        res.push_back(a);
    }
    for (int i = begin; i < a.size(); i++)
    {
        std::swap(a[begin], a[i]);
        permutations(a, begin + 1);
        std::swap(a[begin], a[i]);
    }
}

void Combinatorics::subsets(vector<int> a, int cnt)
{
    if (cnt == a.size())
        res.push_back(path);
    else
    {
        path.push_back(a[cnt]);
        subsets(a, cnt + 1);
        path.pop_back();
        subsets(a, cnt + 1);
    }
}

void Combinatorics::subsets_v2(vector<int> a, int start)
{
    res.push_back(path);
    for (int i = start; i < a.size(); i++)
    {
        path.push_back(a[i]);
        subsets_v2(a, i + 1);
        path.pop_back();
    }
}

void Combinatorics::subsets_v3(vector<int> a, int cnt)
{
    if (cnt == a.size())
    {
        vector<int> temp;
        for (int i = 0; i < a.size(); i++)
            if (path[i])
                temp.push_back(a[i]);
        res.push_back(temp);
    }
    path[cnt] = 0;
    subsets_v3(a, cnt + 1);
    path[cnt] = 1;
    subsets_v3(a, cnt + 1);
}

void Combinatorics::get_res()
{
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    int t[] = {1, 2, 3};
    vector<int> a(t, t + 3);
    Combinatorics *pcm = new Combinatorics();
    pcm->subsets(a, 0);
    pcm->get_res();
    return 0;
}