/*
 * Infix to Postfix Conversion using Stack
 * 
 * Priority order of operators:
 * 1. Exponents (^)           : Priority 3
 * 2. Multiplication (*) and Division (/) : Priority 2 (left to right)
 * 3. Addition (+) and Subtraction (-)    : Priority 1 (left to right)
 * 4. Anything else           : Priority -1
 *
 * Notation Types:
 * - Prefix:  Operators are written BEFORE their operands  (e.g., + A B)
 *            Used in LISP programming language and tree traversals
 * 
 * - Postfix: Operators are written AFTER their operands   (e.g., A B +)
 *            Used in assembly language (easier for computers to evaluate)
 * 
 * - Infix:   Operators are written BETWEEN their operands (e.g., A + B)
 *            MOST COMMONLY USED by humans
 *
 * Example: a + b * (c^d - e)
 * Postfix: a b c d ^ e - * +
 *
 * ╔═══════════════════════════════════════════════════════════════════════════════════════╗
 * ║  Step  │  Symbol  │           Action                    │  Stack   │    Output        ║
 * ╠═══════════════════════════════════════════════════════════════════════════════════════╣
 * ║   1    │    a     │  Operand → Add to output            │          │      a           ║
 * ║   2    │    +     │  Push + to stack                    │    +     │      a           ║
 * ║   3    │    b     │  Operand → Add to output            │    +     │      ab          ║
 * ║   4    │    *     │  * > + → Push * to stack            │   +*     │      ab          ║
 * ║   5    │    (     │  Push ( to stack (lowest priority)  │   +*(    │      ab          ║
 * ║   6    │    c     │  Operand → Add to output            │   +*(    │      abc         ║
 * ║   7    │    ^     │  ^ > ( → Push ^ to stack            │   +*(^   │      abc         ║
 * ║   8    │    d     │  Operand → Add to output            │   +*(^   │      abcd        ║
 * ║   9    │    -     │  - < ^ → Pop ^ add to output        │   +*(-   │      abcd^       ║
 * ║        │          │  Then push - to stack               │          │                  ║
 * ║   10   │    e     │  Operand → Add to output            │   +*(-   │      abcd^e      ║
 * ║   11   │    )     │  Pop till ( and add to output       │   +*     │      abcd^e-     ║
 * ║   12   │   END    │  Pop all and add to output          │          │      abcd^e-*+   ║
 * ╚═══════════════════════════════════════════════════════════════════════════════════════╝
 */

#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to determine the precedence/priority of operators
int precedence(char op) {
    if (op == '^')                  // Exponentiation has highest priority
        return 3;
    if (op == '*' || op == '/')     // Multiplication and Division
        return 2;
    if (op == '+' || op == '-')     // Addition and Subtraction
        return 1;
    return -1;                       // For anything else (like parentheses)
}

// Function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to check if a character is an operand (letter or digit)
bool isOperand(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

// Main function to convert infix expression to postfix
string infixToPostfix(string infix) {
    stack<char> st;    // Stack to store operators and parentheses
    string postfix;    // Result string to store postfix expression
    
    cout << "\n╔════════════════════════════════════════════════════════════════════════════════╗\n";
    cout << "║  Step  │  Symbol  │           Action                    │  Stack   │  Output  ║\n";
    cout << "╠════════════════════════════════════════════════════════════════════════════════╣\n";
    
    int step = 1;
    
    // Process each character in the infix expression
    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];
        
        // Skip whitespace
        if (c == ' ')
            continue;
        
        // Case 1: If character is an operand, add it to output
        if (isOperand(c)) {
            postfix += c;
            
            // Display step
            cout << "║   " << step++ << "    │    " << c << "     │  Operand → Add to output            │  ";
            
            // Display stack
            stack<char> temp = st;
            string stackStr = "";
            while (!temp.empty()) {
                stackStr = temp.top() + stackStr;
                temp.pop();
            }
            cout << stackStr;
            for (int j = stackStr.length(); j < 7; j++) cout << " ";
            cout << "│  " << postfix;
            for (int j = postfix.length(); j < 8; j++) cout << " ";
            cout << "║\n";
        }
        
        // Case 2: If character is '(', push it to stack
        else if (c == '(') {
            st.push(c);
            
            // Display step
            cout << "║   " << step++ << "    │    " << c << "     │  Push ( to stack (lowest priority)  │  ";
            
            // Display stack
            stack<char> temp = st;
            string stackStr = "";
            while (!temp.empty()) {
                stackStr = temp.top() + stackStr;
                temp.pop();
            }
            cout << stackStr;
            for (int j = stackStr.length(); j < 7; j++) cout << " ";
            cout << "│  " << postfix;
            for (int j = postfix.length(); j < 8; j++) cout << " ";
            cout << "║\n";
        }
        
        // Case 3: If character is ')', pop until '(' is found
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            st.pop(); // Remove '(' from stack
            
            // Display step
            cout << "║   " << step++ << "    │    " << c << "     │  Pop till ( and add to output       │  ";
            
            // Display stack
            stack<char> temp = st;
            string stackStr = "";
            while (!temp.empty()) {
                stackStr = temp.top() + stackStr;
                temp.pop();
            }
            cout << stackStr;
            for (int j = stackStr.length(); j < 7; j++) cout << " ";
            cout << "│  " << postfix;
            for (int j = postfix.length(); j < 8; j++) cout << " ";
            cout << "║\n";
        }
        
        // Case 4: If character is an operator
        else if (isOperator(c)) {
            // Pop operators with higher or equal precedence (for left-to-right associativity)
            // For right-to-left (like ^), we only pop if strictly greater
            while (!st.empty() && precedence(st.top()) >= precedence(c) && 
                   (c != '^')) {  // ^ is right associative
                postfix += st.top();
                st.pop();
            }
            
            // Special case for ^ (right associative)
            if (c == '^') {
                while (!st.empty() && precedence(st.top()) > precedence(c)) {
                    postfix += st.top();
                    st.pop();
                }
            }
            
            st.push(c); // Push current operator to stack
            
            // Display step
            cout << "║   " << step++ << "    │    " << c << "     │  Push " << c << " to stack                  │  ";
            
            // Display stack
            stack<char> temp = st;
            string stackStr = "";
            while (!temp.empty()) {
                stackStr = temp.top() + stackStr;
                temp.pop();
            }
            cout << stackStr;
            for (int j = stackStr.length(); j < 7; j++) cout << " ";
            cout << "│  " << postfix;
            for (int j = postfix.length(); j < 8; j++) cout << " ";
            cout << "║\n";
        }
    }
    
    // Pop all remaining operators from stack
    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }
    
    // Display final step
    cout << "║   " << step++ << "    │   END    │  Pop all and add to output          │          │  " << postfix;
    for (int j = postfix.length(); j < 8; j++) cout << " ";
    cout << "║\n";
    cout << "╚════════════════════════════════════════════════════════════════════════════════╝\n";
    
    return postfix;
}

int main() {
    string infix;
    
    cout << "╔════════════════════════════════════════════════════════════════════════════════╗\n";
    cout << "║               INFIX TO POSTFIX CONVERSION USING STACK                          ║\n";
    cout << "╚════════════════════════════════════════════════════════════════════════════════╝\n";
    
    cout << "\nEnter infix expression: ";
    getline(cin, infix);
    
    string postfix = infixToPostfix(infix);
    
    cout << "\n╔════════════════════════════════════════════════════════════════════════════════╗\n";
    cout << "║  Infix Expression:   " << infix;
    for (int i = infix.length(); i < 57; i++) cout << " ";
    cout << "║\n";
    cout << "║  Postfix Expression: " << postfix;
    for (int i = postfix.length(); i < 57; i++) cout << " ";
    cout << "║\n";
    cout << "╚════════════════════════════════════════════════════════════════════════════════╝\n";
    
    return 0;
}

/*
Infix to Prefix Conversion using Stack
1. Reverse the infix with openong to closeing braket and vice vers
2. Infix to Postfix unde\r some condn. like for operaoor if it is not ^ then u just append for equal or grrater
3. Reverse that answer

Example
(A + B)* C - D + F.

Reverse it we will get F + D - C * (B + A )

Convert it to postfix 
F empty F
F +     F
D   +       FD
-   +-      FD
C   +-           FDC
*   +-*             FDC
(   +-*(            FDC
B   +-*(                FDCB
+   +-*(+               FDCB
A   +-*(+               FDCBA
)   +-*                 FDCBA+
                        FDCBA+*-+

STEP 3 is reverse   +-*+ABCDF

*/