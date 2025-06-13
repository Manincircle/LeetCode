class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len=0;//结果
        int curr=0;//存储当前的最长值
        unordered_map<char,int> str;//访问字符序号的哈希表
        int num = s.size();//存储字符串长度
        int start=0;//存储长度的起点序号，也是当前字符串出现唯一一个重复字符的第一个字符的位置
        for(int i=0;i<num;i++){
            if(!str.count(s[i])){//新字符
                str[s[i]] = i;//存储该序号
                curr++;//当前长度加一
            }
            else{
                start = start>str[s[i]]?start:str[s[i]];//如果新访问的字符原来的序号比起点更小，说明其不用考虑
                                                        //如“abba”读到最后一个a时起点应该是第一个b，而不是第一个a
                str[s[i]] = i;//更新字符对应序号
                curr = i-start;//计算新的当前长度，比起真正的起点少计算了一个1
            }
            
            if(len<curr){//如果最大长度小于当前长度就更新
                len=curr;
            }

        }
        return len;//返回结果
    }
};