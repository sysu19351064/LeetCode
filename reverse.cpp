#include <iostream>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        int x_r = 0;
        cout << x << endl;
        while(x != 0){
            if(x_r > 214748364 || x_r < -214748364){
                return 0;
            }
            x_r *= 10;
            x_r += (x%10);
            x /= 10;
        }
        return x_r;
    }
};

//int main() {
//    int x = -2143847412;
//    class Solution solution;
//    cout << solution.reverse(x) << endl;
//    return 0;
//}
