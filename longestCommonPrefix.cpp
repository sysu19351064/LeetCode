#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s = "";
        for(int i = 0; i < strs[0].length(); i++){
            char c = strs[0][i];
            // cout << c <<endl;
            for(auto str : strs){
                if(str[i] != c){
                    return s;
                }
            }
            s += c;
            // cout << s << endl;
        }
        return s;
    }
};


//int main(){
//    vector<string> strs = {"flower","flow","flight"};
//    class Solution solution;
//    cout << solution.longestCommonPrefix(strs) <<endl;
//}

