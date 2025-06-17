class Solution {
public:
    int reverse(int x) {
        string temp = "";//建立空字符串
        bool isNegative = x < 0;//判断正负
        if(x==INT_MIN){//INT_MIN是唯一的特殊情况，取绝对值后正好越界，直接处理
            return 0;
        }
        x = abs(x);//取绝对值

        while (x != 0) {
            temp += (char)('0' + x % 10);//建立反转的字符串
            x /= 10;
        }

        if (temp.empty()) return 0;//说明x==0，直接返回
        string bound = isNegative ? "2147483648" : "2147483647";//确定正数和负数的边界
        if (temp.length() > bound.length() || (temp.length() == bound.length() && temp > bound)) {//长度比最大长直接返回0，长度相等则使用字符串的比较
            return 0;
        }

        int result = stoi(temp);//结果转换成整型

        return isNegative ? -result : result;
    }
};
