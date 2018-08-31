class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i;
        int j;
        long sum;
        vector<int> return_array(2,0);
        for (i = 0; i < nums.size(); i++)
        {
            for (j = i+1; j < nums.size(); j++)
            {
                sum = nums[i] + nums[j];
                if (sum == target)
                {
                    return_array[0] = i;
                    return_array[1] = j;
                    return return_array;
                }
            }
        }
        return return_array;
    }
};

