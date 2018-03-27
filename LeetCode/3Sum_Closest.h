//best answer:https://leetcode.com/problems/3sum-closest/discuss/7883/C++-solution-O(n2)-using-sort
#pragma once
#include<vector>
#include<math.h>
#include<algorithm>

using namespace std;

namespace three_Sum_Closest{
	class Solution {
	public:
		void match(int difference, vector<int>& nums, int begin, int* result) {
			//int result[2];//[delta,index]

			int end = nums.size();
			if (difference <= nums[begin])
			{
				result[0] = abs(difference - nums[begin]);
				result[1] = begin;
			}
			else if (difference >= nums[nums.size()-1])
			{
				result[0] = abs(difference - nums[nums.size()-1]);
				result[1] = nums.size() - 1;
			}
			else {
				while ((end - begin)>1) {
					int mid = (begin + end) / 2;
					if (nums[mid]<difference)
						begin = mid;
					else end = mid;
				}
				result[1] = abs(difference - nums[begin])<abs(difference - nums[end]) ? begin : end;
				result[0] = abs(difference - nums[result[1]]);
			}

		}

		int threeSumClosest(vector<int>& nums, int target) {
			sort(nums.begin(), nums.end());

			int min_delta = abs(target - (nums[1] + nums[2] + nums[0]));
			int result[3];  result[0] = nums[0];  result[1] = nums[1];  result[2] = nums[2];
			int difference;
			int sz = nums.size();
			for (int i = 0; i<sz - 2; i++)
			{
				for (int j = i + 1; j<sz - 1; j++)
				{
					difference = target - (nums[i]+nums[j]);
					int resu[2];//[delta,index]
					match(difference, nums, j + 1, resu);

					if (resu[0]<min_delta) {
						result[0] = nums[i];
						result[1] = nums[j];
						result[2] = nums[resu[1]];
						min_delta = resu[0];
					}

					if (min_delta == 0) break;
				}
			}

			return result[0] + result[1] + result[2];
		}
	};

}//namespace three_Sum_Closest
