class Solution {
public:
    bool isPalindrome(int x) {
        int sta[64];
        int vec[64];
        int i;
        int j;
        if (x < 0 || (x % 10 == 0 && (x > 0)))
            return false;
        if (x < 10) //一位整数总是回文数
            return true;
        i = 0;
        while (x > 0) {
            vec[i] = x % 10;
            sta[i] = x % 10;
            x = x / 10;
            i++;
        }
        j = i - 1;
        i = 0;
        while (j >= 0) {
            if (sta[i] != vec[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};
