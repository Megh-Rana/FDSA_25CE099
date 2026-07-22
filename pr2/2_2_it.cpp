#include <bits/stdc++.h>
using namespace std;
int cnt=0;

int find_iterative(vector<int> nums,int target)
{
    int left=0,right=nums.size()-1,mid;
    while(left<=right)
    {
        mid=left+(right-left)/2;
        cnt++;
        if(target==nums[mid])
        {
            return mid;
        }
        else if(target<nums[mid])
        {
            right=mid-1;
        }
        else
        {
            left=mid+1;
        }
    }
    return -1;
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
    int result=find_iterative(nums,target);
    if(result!=-1)
    {
        cout << result << endl;
    }
    else
    {
        cout << "Element " << target << " is not present in the array"<< endl;
    }
    cout << cnt;    
    
}