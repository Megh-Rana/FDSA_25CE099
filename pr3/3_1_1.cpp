#include <bits/stdc++.h>
using namespace std;

vector<int> sort_approach1(vector<int> &nums)
{
    int n=nums.size();
    for(int i=0;i<n-1;i++)
    {
        bool swapped = false;
        for(int j=0;j<n-i-1;j++)
        {
            if(nums[j]>nums[j+1])
            {
                swap(nums[j],nums[j+1]);
                swapped=true;
            }
        }
        if(!swapped)
            break;        
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
    nums = sort_approach1(nums);
    for(int i=0;i<n;i++)
    {
        cout << nums[i] << " ";
    }
}