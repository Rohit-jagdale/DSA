class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size(); 

    std::sort(nums.begin(), nums.end()); 
    int result = nums[0]+nums[1]+nums[2];
    int diff = std::numeric_limits<int>::max();
    
        result = nums[0]+nums[1]+nums[2];
        diff = abs(result - target);
    for(int i = 0; i<nums.size()-2; i++){
        if(diff==0){
            return result;
        }
        int left = i+1;
        int right = nums.size()-1;
        while(left<right){
            int sum = nums[i]+nums[left]+nums[right];
            int newDiff = abs(sum - target);
            if(newDiff<diff){
                diff = newDiff;
                result = sum;
            }
            if (sum==target){
                return result;
            } else if (sum > target){
                right--;
            } else{
                left++;
            }
        }
    }
    return result;
    }
};
