#include <iostream>
#include <stack>
#include <string>  
#include<cmath>

//Functions declaration
int precedence(char op);
void infix_to_postfix(const std::string &s);
void evaluation(const std::string out);

//Functions definitions
int precedence(char op) {

	// Low precedence
	if (op == '+' || op == '-') {
		return 1;
	}
	// high precedence
	else if (op == '*' || op == '/') {
		return 2;
	}
	else if (op == '^' ) {
		return 3;
	}
	else {
		return -1;
	}
}

void infix_to_postfix(const std::string &s) {
	int count1 = 0;  // to count opening brackets
	int count2 = 0;  // to count closing brackets

	std::stack<char> st1; // STL stack
	std::string output;

	for (int i = 0; i < s.length(); i++) {
		char ch = s[i];

		if (isdigit(ch)) {   // to check if character is digit or not.
			while (i < s.length() && isdigit(s[i])) {
				output += s[i];
				i++;
			}
			output += " ";
			i--;
		}

		else if (ch == '(') {  // to check if character is opening bracket or not.
			count1++;  // to count number of opening brackets.
			st1.push(ch);
		}

		else if (ch == ')') {  // to check if character is closing bracket or not.
			count2++;     // to count number of closing brackets.

			// if the element at top of stack is other than opening bracket then add it into output and pop it from stack.

			while (!st1.empty() && st1.top() != '(') {
				output += st1.top();
				output += " ";
				st1.pop();
			}

			// if the element at top of stack is opening bracket then pop it from stack.
			if (!st1.empty() && st1.top() == '(') {
				st1.pop();
			}
		}

		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {

			// if the operator at top of stack has equal or greater precedence than that from input operator,then add it to output
			//and pop from stack.
			while (!st1.empty() && precedence(st1.top()) >= precedence(ch)) {
				output += st1.top();
				output += " ";
				st1.pop();
			}
			// if stack is empty then just push the operator in stack.
			st1.push(ch);
		}

		else if (isspace(ch)) {
			continue;
		}

		else {
			std::cout << "Invalid character or operator!" << std::endl;
			return;
		}
	}
	// At the end, if stack is not empty then add all elements from stack into output and pop them one by one.
	while (!st1.empty()) {
		output += st1.top();
		st1.pop();
	}

	// check if opening and closing brackets are equal or not.
	if (count1 == 0 && count2 == 0) {
		std::cout << "No brackets in the expression!" << std::endl;
		std::cout << "Infix to postfix expression:";
		std::cout << output << std::endl;
	}

	else if ((count1 == count2) && count1 > 0 && count2 > 0) {
		std::cout << "Brackets are Balanced!" << std::endl;
		std::cout << "Infix to postfix expression:";
		std::cout << output << std::endl;
	}

	else {
		std::cout << "Brackets are not balanced!" << std::endl;
		return;
	}

	// call evaluation function to evaluate postfix expression.
	evaluation(output);

}

void evaluation(const std::string out) {
	std::stack<int> st2;

	for (int i = 0; i < out.length(); i++) {
		char ch = out[i];

		if (isdigit(ch)) {
			// handling multiple digits case.
			int appending = 0;
			while (i < out.length() && isdigit(out[i])) {
				appending = appending * 10 + (out[i] - '0');  // ASCII value of 0 is 48
				i++;
			}

			// Push the appended value into stack.
			st2.push(appending);
			i--;
		}


		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {

			if (st2.empty()) {
				std::cout << "Stack is empty!" << std::endl;
				return;
			}

			// if operator then pop the element at top of stack.
			int op2 = st2.top();
			st2.pop();

			if (st2.empty()) {
				std::cout << "Stack is empty!" << std::endl;
				return;
			}

			//Again pop the element which is at top of stack.
			int op1 = st2.top();
			st2.pop();

			int answer;
			switch (ch) {
			case '+':
				answer = op1 + op2;
				break;
			case '-':
				answer = op1 - op2;
				break;
			case '*':
				answer = op1 * op2;
				break;
			case '/':
				if (op2 == 0) {
					std::cout << " Division by zero is not possible!" << std::endl;
					return;
				}
				answer = op1 / op2;
				break;
			case '^':
				answer = pow(op1, op2);
				break;
			default:
				std::cout << "Invalid operator!" << std::endl;
				return;
			}
			//after performing the operation push the answer into stack.
			st2.push(answer);
		}

		else if (isspace(ch)) {
			continue;
		}
		else {
			std::cout << "Invalid postfix expression!" << std::endl;
			return;
		}
	}

	// displaying evaluated postfix expression.
	std::cout << "Simplified Postfix expression:" << st2.top() << std::endl;
}

int main(int argc, char*argv[]) {

	std::cout << "Please read these instruction first if you want to take input from user" << std::endl;
	std::cout << "If you want to add multidigits write like this:";
	std::cout << "101" << std::endl;
	std::cout << "If you want to consider every digit as single character then write like this:";
	std::cout << "1 0 1" << std::endl;

	std::string e;

	if (argc == 1) {
		std::string exp;
		std::cout << "No command line argument is given!" << std::endl;
		std::cout << "Enter an expression:";
		getline(std::cin, exp);
		infix_to_postfix(exp);
	}
	else {

		for (int i = 0; i < argc; i++) {
			std::cout << "Argument " << i + 1 << "=" << argv[i] << std::endl;
		}

		if (argc == 2) {
			for (int i = 1; i < argc; i++) {
				infix_to_postfix(argv[i]);
			}
		}

		else if (argc > 2) {
			for (int i = 1; i < argc; i++) {
				e += argv[i];
			}
			std::cout << e << std::endl;
			infix_to_postfix(e);
		}


	}
}
