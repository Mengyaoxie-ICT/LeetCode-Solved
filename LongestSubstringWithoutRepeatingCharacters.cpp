class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int m[256] = {0}, res = 0, left = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (m[s[i]] == 0 || m[s[i]] < left) {
                res = max(res, i - left + 1);
            } else {
                left = m[s[i]];
            }
            m[s[i]] = i + 1;
        }
        return res;
    }
};


/* 
 * m[x]记录了字符x出现的最后位置，遍历每个字符，更新该字符出现的最后位置（Line11）
 * 当m[x]为0（该字符没有出现过），x可以加入subsring中，和res比较大小
 * 当m[x]不为0，但m[x]小于left，即x最后出现的位置在left左边（由于left指向substring的开头，因此上一个x已经不在substring中了），所以将x纳入substring
 * 当m[x]不为0且大于等于left时，即上一个x就在substring中，所以left要移动到上一个x的后一个位置上
 * 注意：left在结束时不一定指向loogest substring的起始位置。例如s="abcdeca"，当c再一次出现时，left移动到d处，在这之前res=5（abcde的长度），检查
 * 下一个a，m[a]<left，所以a加入substring，长度为4，小于abcde的5，因此最后结果是res=5
*/
