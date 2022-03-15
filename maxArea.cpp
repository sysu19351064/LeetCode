#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size()-1;
        int maxarea = 0;
        while(l < r){
            maxarea = max(maxarea, (r-l)*min(height[l], height[r]));
            if(height[l] < height[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return maxarea;
    }

    int max(int a, int b){
        return (a>b)?a:b;
    }

    int min(int a, int b){
        return (a<b)?a:b;
    }
};

//int main(){
//    vector<int> height = {1,8,6,2,5,4,8,3,7};
//    class Solution solution;
//    cout << solution.maxArea(height) <<endl;
//}