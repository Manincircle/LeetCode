class Solution {
public:
    int max = 0;//记录最大值
    int right=0;//起点
    string longestPalindrome(string s) {
        int start = 0;
        int n = s.size();
        for(int i=0;i<n;i++){
            check(s,i,i,n);//考虑奇数和偶数回文字符串
            check(s,i,i+1,n);
        }
        return s.substr(right,max);
    }

    void check(string s,int i,int j,int n){
        while(i>-1&&j<n&&s[i]==s[j]){//左==右就继续下去
            if(max<j-i+1){//小于当前回文的长度
                max = j-i+1;//更新最大值和起点
                right = i;
            }
            i--;
            j++;
        }
    }
};