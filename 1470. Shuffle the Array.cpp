/*
Given the array nums consisting of 2n elements in the form [x1,x2,...,xn,y1,y2,...,yn].

Return the array in the form [x1,y1,x2,y2,...,xn,yn].



Example 1:

Input: nums = [2,5,1,3,4,7], n = 3
Output: [2,3,5,4,1,7]
Explanation: Since x1=2, x2=5, x3=1, y1=3, y2=4, y3=7 then the answer is [2,3,5,4,1,7].
Example 2:

Input: nums = [1,2,3,4,4,3,2,1], n = 4
Output: [1,4,2,3,3,2,4,1]
Example 3:

Input: nums = [1,1,2,2], n = 2
Output: [1,2,1,2]
*/


#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	vector<int> shuffle(vector<int>& nums, int n) {
		vector<int> first;
		vector<int> second;
		vector<int> answer;
		for (int i = 0; i < n; i++) {
			first.push_back(nums[i]);
		}
		for (int i = n; i < 2 * n; i++) {
			second.push_back(nums[i]);
		}
		for (int i = 0; i < n; i++) {
			answer.push_back(first[i]);
			answer.push_back(second[i]);
		}
		nums = answer;
		return nums;
	}
};



int main() {
	int c, n;
	cin >> c >> n;
	vector<int>nums(c);
	for (int i = 0; i < nums.size(); i++) {
		cin >> nums[i];
	}
	Solution Solution;
	vector <int> check = Solution.shuffle(nums, n);
	vector<int> result;
	for (int i = 0; i < nums.size(); i++) {
		cout << nums[i] << " ";
	}
}