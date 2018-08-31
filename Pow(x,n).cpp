class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0)
            return 1 / power(x, -n);
        else return power(x, n);
    }
    double power(double x, int n) {
        if (n == 0) return 1;  //要先判断n是否为0再求half；如果先求half，当n为0时，return power(x, 0)即出错
        double half = power(x, n / 2);  
        if (n % 2 == 0)
            return half * half;
        else return half * half * x;
    }
};
