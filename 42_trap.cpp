#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int leftmax = 0;
        int rightmax = 0;
        int sum = 0;
        while(left < right){
            leftmax = max({leftmax, height[left]});
            rightmax = max({rightmax, height[right]});
            if(leftmax < rightmax) {
                sum += (leftmax-height[left]);
                left++;
            }else{
                sum += (rightmax - height[right]);
                right--;
            }
        }
        return sum;
    }
};

int main(){
    vector<int> height = {4,2,0,3,2,5};
    class Solution solution;
    cout << solution.trap(height) << endl;
    return 0;
}
