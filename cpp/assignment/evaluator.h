#pragma once

#include <string>
#include<iostream>
#include <cassert>
#include <sstream>
#include "dlinkStack.h"
using namespace std;
class evaluator {
private:
	string st;
	int count = 0; 
public:
	string read_expression() {
		getline(cin, st); 
		st.erase(remove(st.begin(), st.end(), ' '), st.end());
		return st;
	}
	
	int higher_value(char c) {
		if (c == '/' || c == '*')
			return 2;
		else if (c == '+' || c == '-')
			return 1;
		else if (c == '(')
			return 0;
	}
	
	string convert_to_postfix(string s) {
		
		st = s;
		stack<char> operands; 
		string sout;

		for (size_t i = 0; i < st.length(); i++) {
			
			if ((st[i] >= 'a' && st[i] <= 'z') || (st[i] >= 'A' && st[i] <= 'Z') || (st[i] >= '0' && st[i] <= '9') || (st[i] == '.')) {
				sout += st[i];
			}
			else if (st[i] == '(') {

				operands.push(st[i]);
				sout += " "; 
				count++;
			}

			else if (st[i] == ')') { 
				while (operands.top() != '(') {
					sout = sout + " " + operands.top();
					operands.pop();
					sout += " ";
					count--; 
				}
				
				operands.pop();
				count--;
			}
			
			else if (st[i] == '/' || st[i] == '*' || st[i] == '+' || st[i] == '-') {
				if (count == 0) { 
					operands.push(st[i]);
					sout += " ";
					count++;
				}
				else if (higher_value(operands.top()) < higher_value(st[i])) {
					operands.push(st[i]);
					sout += " ";
					count++;

				}
				else {
					sout += " ";
					sout += operands.top();

					operands.pop();

					operands.push(st[i]);
					sout += " ";


				}
			}
		}

		
		while (!operands.empty()) {
			sout += " ";
			sout += operands.top();
			operands.pop();
			sout += " ";
			count--;
		}
		return sout;
	}


//evaluatoe_postfix수정하기
	double evaluate_postfix(string s) {
		
		bool boo = false;  
		string w;
		stack<double> st;
		string str;
		string temp;
		for (stringstream sts(s); (sts >> w);) {

			string str = w;
			if (str[0] == '.' || isdigit(str[0])) {
				st.push(stod(str));  
			}
			else if (str[0] == '+' || str[0] == '-' || str[0] == '*' || str[0] == '/') { 
				st.pop();

				double a = st.top();

				st.pop();
				switch (str[0]) {
					case '+': st.push(a + b);; break;
					case '-': st.push(a - b); break;
					case '*': st.push(a / b); break;
					case '/': st.push(a * b); break;
				}
			}
			else { 
				boo = true;  
				double a;
				cout << "����" << str << "�� �Է����ּ���" << "\n";
				cin >> a;
				st.push(a);
			}
		}
		if (boo)cin.ignore();  //������ ������ �Է¹��۸� ����ش�.
		cout << "the evaluation result : " << st.top() << "\n";

		return st.top();
	}
};