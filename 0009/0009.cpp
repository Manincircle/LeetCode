class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0||(x%10==0&&x!=0)) return false;
        else{
            vector<int> index;//储存序号
            while (x) {
                index.push_back(x % 10);//将每个序号存起来
                x /= 10;
            }
            int left=0;
            int right = index.size()-1;
            while(left<right){
                if(index[left]!=index[right]) return false;//直接比较回文
                left++;
                right--;
            }
            return true;
        }
    }
};