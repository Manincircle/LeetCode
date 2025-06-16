class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;//不加这一行会卡死
        vector<char> buffer;//先是数组，然后统一变换成字符串
        int num = s.size();
        int index = 0;
        int left = 2 * (numRows - 1);//考虑第4行，观察z字形，第一行间隔2 * (numRows - 1)个，就添加一个
        int right = 0;//除开最上和最下两行，中间间隔是右两个交错组成，为了方便，默认一开始是0，然后不处理0的添加
        for (int i = 0; i < numRows; i++) {
            for(index = i;index<num;){
                if (left!=0) {
                    buffer.push_back(s[index]);
                }
                index += left;
                if (index < num && right!=0) {
                    buffer.push_back(s[index]);
                }
                index += right;
            }
            left -= 2;//注意到两个间隔和一定是定值，且每一行之间的同一种间隔相差2，从而模拟下一行
            right += 2;
        }
        return string(buffer.begin(), buffer.end());
    }
};