#include<iostream>
#include "evaluator.h"

using namespace std;
int main() {
    evaluator e;

    while (true) {
        cout << "infix형 문자열을 입력하시오\n";
        string str = e.read_expression();
        cout << "infix형 : " + str + '\n';
        if (str == "exit")break;
        string result = e.convert_to_postfix(str);
        cout << "postfix형 : "+result + '\n';
        cout << "계산 결과: ";
        cout << e.evaluate_postfix(result);
        cout<<"\n-----------------------------------------------------\n";
    }
    cout << "종료";


    return 0;
}