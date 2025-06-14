class Solution {//不吃苦版本
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int nums1size = nums1.size();
        int nums2size = nums2.size();
        int totalsize = nums1size+nums2size;
        nums1.resize(nums1size+nums2size);
        for(int i = 0;i<nums2size;i++){
            nums1[nums1size+i] = nums2[i];
        }//其实也可以直接用insert
        sort(nums1.begin(),nums1.end());
        return totalsize % 2 == 0 ?
        (nums1[totalsize / 2 - 1] + nums1[totalsize / 2]) / 2.0 :
        nums1[totalsize / 2];
    }
};