class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> track_indexes;
        for(int i=0; i<nums.size(); i++){
            int numToFind = target - nums[i];
            auto it = find(nums.begin(), nums.end(), numToFind);
            // cout << i << " " << nums[i] << " " << numToFind << endl;
            int indx = distance(nums.begin(),it);
            if(it != nums.end() and indx != i){
                track_indexes.push_back(i);
                track_indexes.push_back(indx);
                break;
            }
        }
        return track_indexes;
    }
};


// https://leetcode.com/problems/two-sum

// 74 ms [too avg]