#include <bits/stdc++.h>
using namespace std;

int find_recursive(vector<int> nums, int target, int idx = 0)
{
    if(idx == nums.size())
    {
        return -1;
    }
    if(nums[idx] == target)
    {
        return idx;
    }
    return find_recursive(nums, target, idx + 1);
}


int main()
{
    int n,target;
    cin >> n;
 
    vector<int> nums;
    for(int i=0;i<n;i++)
    {
        int num;
        cin >> num;
        nums.push_back(num);
    }

   cin >> target;
    int result=find_recursive(nums,target);
    if(result!=-1)
    {
        cout << result << endl;
        cout << result+1;        
    }
    else
    {
        cout << "Element " << target << " is not present in the array"<< endl;
        cout << nums.size();
    }
    
    
}

