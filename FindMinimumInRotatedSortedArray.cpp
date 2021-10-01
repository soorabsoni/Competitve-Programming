#include<iostream>
#include<vector>
using namespace std;

int findMin(vector<int>& nums)
{
    int n=nums.size();
    if(nums[0]<nums[n-1])
        return nums[0];
    int low=0;
    int high=n-1;
    int ans=nums[0];
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(nums[mid]>=nums[0])
            low=mid+1;
        else
        {
            ans=nums[mid];
            high=mid-1;
        }
    }
    return ans;  
}

int main()
{
    vector<int> nums;
    int n;
    
    cout<<"Enter size of array: ";
    cin>>n;
    
    cout<<"Enter rotated sorted array: ";
    for(int i=0;i<n;i++)
    {
        int element;
        cin>>element;
        nums.push_back(element);
    }
    
    int ans=findMin(nums);
    cout<<"Minumum is rotated sorted array: "<<ans<<endl;
    
    return 0;
}