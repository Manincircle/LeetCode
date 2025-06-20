class Solution {
public:
    int myAtoi(string s) {
        double temp = 0;
        int index=0;
        while(s[index]==' '){//忽略空格
            index++;
        }
        int flag = s[index]=='-'?-1:1;//判断正负
        if(s[index]=='-'||s[index]=='+') index++;
        int size=s.size();
        while(index<size){
            if(s[index]-'0'>-1&&s[index]-'0'<10)
            {
                temp = temp*10+(double)(int)(s[index] - '0');
                index++;
            }
            else break;//不是数字直接打断
        }
        temp*=flag;
        if(temp>(double)INT_MAX) return INT_MAX;//其实偷懒了（
        else if(temp<(double)INT_MIN) return INT_MIN;
        else return (int)temp;
    }
};