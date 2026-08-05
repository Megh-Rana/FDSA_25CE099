#include <bits/stdc++.h>
using namespace std;

vector<int> sort_approach2(vector<int> &nums)
{
    int n=nums.size();
    for(int i=0;i<n-1;i++)
    {
        int min_idx=i;
        for(int j=i;j<n;j++)
        {
            if(nums[j] < nums[min_idx])
                min_idx = j;
        }      
        swap(nums[min_idx],nums[i]);
    }
    return nums;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
    {
        cin >> nums[i];
    }
    nums = sort_approach2(nums);
    for(int i=0;i<n;i++)
    {
        cout << nums[i] << " ";
    }
}