#include<iostream>
#include<vector>
#include<Windows.h>

#include"3Sum_Closest.h"

using namespace std;

int main()
{
	three_Sum_Closest::Solution s;
	//int S[4] = { -1, 2, 1, - 4 };
	vector<int> S;
	S.push_back(-1);
	S.push_back(2);
	S.push_back(1);
	S.push_back(-4);
	int target = -1;
	cout << s.threeSumClosest(S, target) << endl;
	system("pause");
	return 0;
}