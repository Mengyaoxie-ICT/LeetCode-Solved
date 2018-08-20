class Solution {
public:
    int reverse(int x) {
        long tmp = (long)x;
        int flag = 0;
        int a[128];
        int i;
        int j;
        long index;
        for (i = 0; i < 128; i++)
            a[i] = -1;
        if (tmp < 0) {
            flag = 1;
            tmp = -tmp;
        }
        i = 0;
        while (tmp > 0) {
            a[i] = tmp % 10;
            tmp = tmp / 10;
            i++;
        }
        index = 1;
        tmp = 0;
        for (j = i - 1; j >= 0; j--) {
            tmp += a[j] * index;
            index = index * 10;
        }
        if (tmp > pow(2,31) - 1)
            return 0;
        if (flag)
            tmp = -tmp;
        return tmp;
    }
};
