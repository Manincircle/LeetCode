class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;//new一个结果
        unordered_map<int,int> hash;//生成一个哈希表（如果用map会变慢，因为访问效率会慢一点），储存nums数组元素值对应的序号
        int num = nums.size();//存储nums数组的元素个数，避免在for循环里面访问导致变慢，不过编译器应该会自己优化......吧
        for(int i=0;i<num;i++){
            if(!hash.count(target - nums[i]))//如果哈希表里面不存在目标值和当前元素的差值
                                             //（也就是还没有访问到一个值能和已经存储到哈希表里面的数组元素值相加为target的值），就把这个元素存起来
            {
                hash[nums[i]] = i;//储存对应序号，如果有重复元素就覆盖，不影响结果（两数之和）
            }
            else{//存在，也就是访问到了目标值和当前元素的差值，即得到两个元素相加为target
                result.push_back(i);//将当前序号存入结果
                result.push_back(hash[target-nums[i]]);//将根据当前序号对应数组元素值和target得到的另一个已经在哈希表里面的数组元素
                                                       //的序号存入结果
                break;//退出循环
            }
        }
        return result;//返回结果
    }
};