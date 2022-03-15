#include <iostream>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        int inte[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string romans[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};\
        string s_r = "";
        for(int i = 0; i < 13; i++){
            while(num >= inte[i]){
                num -= inte[i];
                s_r += romans[i];
            }
        }
        return s_r;
    }
};

//int main(){
//    int num = 1994;
//    class Solution solution;
//    cout << solution.intToRoman(num) <<endl;
//}
