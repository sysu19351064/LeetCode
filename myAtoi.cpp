#include <iostream>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int re = 0;
        int i = 0;
        int flag = 1;
        // 第一阶段
        for(; i < s.length(); i++){
            if(s[i] != ' ')
                break;
        }
        if(s[i] == '-'){
            flag = -1;
            i++;
        }
        else if(s[i] == '+'){
            i++;
        }
        for(;i < s.length(); i++){
            if(s[i] >= 48 && s[i] <= 57){
                if(flag == 1 && re > (2147483647-(s[i]-48)*flag)/10){
                    return 2147483647;
                }
                if(flag == -1 && re < (-2147483648-(s[i]-48)*flag)/10){
                    return -2147483648;
                }
                re *= 10;
                re += (s[i]-48)*flag;
            }
            else{
                break;
            }
        }
        return re;
    }
};

//int main() {
//    string x = "-42";
//    class Solution solution;
//    cout << solution.myAtoi(x) << endl;
//    return 0;
//}

