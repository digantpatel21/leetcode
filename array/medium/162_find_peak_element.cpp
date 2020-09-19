class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        
        if(nums.size()  == 1)
            return 0;
        
        int l = 0, r = nums.size()-1;
        int mid = 0;
        if(nums[l] > nums[l+1])
            return l;
        
        if(nums[r] > nums[r-1])
            return r;
        
        
        while(l < r) {
            
            mid = l + (int)((r-l)/2);
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) {
                return mid;
            }
            
            if(nums[mid] < nums[mid-1] ) {
                r = mid;
            } else {
                l = mid;
            }
        }
        
        return r;
        
    }
};