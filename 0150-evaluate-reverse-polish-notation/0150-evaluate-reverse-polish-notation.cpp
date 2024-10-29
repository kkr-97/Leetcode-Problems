class Solution {
public:
    int calc(int a, int b, string token){
            if (token == "+")
                return a+b;
            else if (token == "-")
                return b-a;
            else if (token == "*")
                return a*b;
            return b/a;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for(string token : tokens){
            if(!(token == "+" || token == "-" || token == "*" || token == "/")){
                stk.push(stoi(token));
            }
            else{
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                int res = calc(a, b, token);
                cout << a << " " << token << " " << b << " " << res << endl;
                stk.push(res);
            }
        }
        return stk.top();
    }
};