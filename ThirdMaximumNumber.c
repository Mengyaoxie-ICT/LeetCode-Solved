class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int current;
        long firstmax;
        long secondmax;
        long thirdmax;
        int i;
   //     int temp;
        firstmax = secondmax = thirdmax = LONG_MIN; //LONG_MIN 当使用INT_MIN(-2147483648)时，输出前的判断会出错。
        
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return nums[0] >= nums[1] ? nums[0] : nums[1];
        
   /*     firstmax = nums[0] >= nums[1] ? nums[0] : nums[1];
        firstmax = firstmax >= nums[2] ? firstmax : nums[2];
        thirdmax = nums[0] < nums[1] ? nums[0] : nums[1];
        thirdmax = thirdmax < nums[2] ? thirdmax : nums[2];
        for (i = 0; i < 3; i++)
        {
            if (nums[i] != firstmax && nums[i] != thirdmax)
                secondmax = nums[i];
        }
    //    cout << firstmax << secondmax << thirdmax;
        if (nums.size() <= 3) return thirdmax;
        for (i = 3; i < nums.size(); i++)
        {
            if (nums[i] > firstmax)
                firstmax = nums[i];
            else if (nums[i] > secondmax)
                secondmax = nums[i];
            else if (nums[i] > thirdmax)
                thirdmax = nums[i];
        }
*/
        for (i = 0; i < nums.size(); i++)
        {
            if (nums[i] > firstmax)
            {
                //temp ...   使用temp作为中间变量赋值时，可能出现错误。secondmax以及thirdmax可能赋值成0
                thirdmax = secondmax;
                secondmax = firstmax;
                firstmax = nums[i];
            }    
            else if (nums[i] > secondmax && nums[i] < firstmax)
            {
                thirdmax = secondmax;
                secondmax = nums[i];
            }
            else if (nums[i] > thirdmax && nums[i] < secondmax)
                thirdmax = nums[i];
            cout << firstmax << " " << secondmax << " " << thirdmax << endl;
        }
        if (thirdmax == LONG_MIN || thirdmax == secondmax)
            return firstmax;
        else return thirdmax;
    }
};
