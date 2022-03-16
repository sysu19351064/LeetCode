#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
//        if(s.length() == 1){
//            return false;
//        }
        stack<char> sta;
        for(auto c : s){
            if(c == '(' || c == '[' || c == '{'){
                sta.push(c);
            }
            else if(c == ')' && !sta.empty() && sta.top() == '('){
                sta.pop();
            }
            else if(c == ']' && !sta.empty() && sta.top() == '['){
                sta.pop();
            }
            else if(c == '}' && !sta.empty() && sta.top() == '{'){
                sta.pop();
            }
            else{
                return false;
            }
        }
        if(sta.empty()){
            return true;
        }
        return false;
    }
};


int main(){
    string s = ")";
    class Solution solution;
    cout << solution.isValid(s) << endl;
}

