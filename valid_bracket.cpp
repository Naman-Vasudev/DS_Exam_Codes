#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool is_valid ( string expression)
{
    stack <char> S;
    for (char ch: expression)
    {
        if (ch=='(' || ch=='{' || ch=='[')
        {
            S.push(ch);
        }

        else if (ch==')' || ch==']' || ch=='}')
        {
            if (S.empty()) return false; 
            char top=S.top();
            S.pop();
            if ((ch==')' && top!='(') || (ch=='}' && top!='{') || (ch==']' && top!='['))
                return false;
        }   
    }
    return S.empty();
}



int main()
{
   string expr;
   cout<<"Enter a string: ";
   cin>>expr;
   
   if (is_valid(expr)) cout<<"VALID";
   else cout<<"INVALID";
    return 0;
}
/*
Time and Space Complexity is O(n) 
*/