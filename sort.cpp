# include <cstdio>
# include <algorithm>
# include <iostream>
# include <vector>

using namespace std;


class Sort
{
public:    
    void bubble_sort(vector<int>&a);
    vector<int> merge(vector<int>left, vector<int>right);
    vector<int> merge_sort(vector<int>a, int start, int end);
    void quick_sort(vector<int>&a, int start, int end);
    int partition(vector<int>a, int start, int end);
    vector<int> heap_sort(vector<int>a);
    void heaplify();
private:

};

// quick sort 
void Sort::quick_sort(vector<int>a, int start, int end)
{
    if (start < end)
    {
        int mid = Sort::partition(a, start, end);
        Sort::quick_sort(a, start, mid);
        Sort::quick_sort(a, mid + 1, end);            
    }
}

int Sort::partition(vector<int>a, int start, int end)
{
    int pivot = a[start];
    while (start < end)
    {
        while (a[end] >= pivot) end --;
        while (a[start] <= pivot) start ++;
        swap(a[start], a[end]);
    }
    return start;
}

// bubble sort
void Sort::bubble_sort(vector<int>&a)
{    
    for (int i = 0; i < a.size(); i ++)
    {
        bool flag = true;
        for (int j = a.size() - 1; j > i; j --)
        {
            if (a[j] < a[j - 1])
            {
                flag = false;
                std::swap(a[j], a[j - 1]);
            }
        }
        if (flag) break;
    }
}

// merge sort 
vector<int> Sort::merge_sort(vector<int>a, int start, int end)
{    
    vector<int> res;
    if (start > end) return res;    
    if (start == end) 
    {
        //return res;
        res.push_back(a[start]);
        return res;
    }
    int mid = start + (end - start) / 2;    
    vector<int> left = merge_sort(a, start, mid);
    vector<int> right = merge_sort(a, mid + 1, end);
    res = merge(left, right);
    return res;
}

vector<int> Sort::merge(vector<int>left, vector<int>right)
{
    // merge two sorted vector 
    vector<int> res;
    int p = 0;
    int q = 0;
    for (; p < left.size() && q < right.size(); )
    {
        if (left[p] <=right[q]) res.push_back(left[p ++]);       
        else res.push_back(right[q ++]);       
    }

    while (p < left.size()) res.push_back(left[p ++]);                
    while (q < right.size()) res.push_back(right[q ++]);
    
    for (int i = 0; i < res.size(); i ++) cout << res[i] << " ";
    cout << endl;
    return res;
}

// heap sort
vector<int> Sort::heap_sort(vector<int>a)
{
    vector<int> res;
    return res;

}

void Sort::heaplify()
{

}

int test_merge_sort()
{
    int ta[] = {3,4,6,7,8,6,2,5,7,8,6,7,8,2,3,5};
    vector<int> a (ta, ta + 16); // 2,7,8,3,4,6,7,8,6,2,5,7,8,6,7,8,2,3,5};   
    Sort* sort = new Sort();
    vector<int>res = sort->merge_sort(a, 0, a.size());       
    cout << res.size() << endl; 
    for (int i = 0; i < res.size(); i ++) cout << res[i] << " ";
    cout << endl; 

    std::sort(a.begin(), a.end());

    for (int i = 0; i < a.size(); i ++) cout << a[i] << " ";
    cout << endl;
    return 0;
}

int main()
{
    int ta[] = {3,4,6,7,8,6,2,5,7,8,6,7,8,2,3,5};
    vector<int> a (ta, ta + 16); // 2,7,8,3,4,6,7,8,6,2,5,7,8,6,7,8,2,3,5};
    Sort* sort = new Sort();
    sort->bubble_sort(a);
    for (int i = 0; i < a.size(); i ++) cout << a[i] << " ";
    cout << endl;
    return 0;   
}