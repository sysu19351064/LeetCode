#include <iostream>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int inte[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string romans[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};\
        int num = 0;
        for(int i = 0; i < 13; i++){
            while(s.substr(0, i%2+1) == romans[i]){
                num += inte[i];
                s.erase(0, i%2+1);
            }
        }
        return num;
    }
};

//int main(){
//    string s = "MCMXCIV";
//    class Solution solution;
//    cout << solution.romanToInt(s) <<endl;
//}





