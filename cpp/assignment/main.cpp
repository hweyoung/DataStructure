#include<iostream>
#include "evaluator.h"

using namespace std;
int main() {
    evaluator e;

    while (true) {
        cout << "infix�� ���ڿ��� �Է��Ͻÿ�\n";
        string str = e.read_expression();
        cout << "infix�� : " + str + '\n';
        if (str == "exit")break;
        string result = e.convert_to_postfix(str);
        cout << "postfix�� : "+result + '\n';
        cout << "��� ���: ";
        cout << e.evaluate_postfix(result);
        cout<<"\n-----------------------------------------------------\n";
    }
    cout << "����";


    return 0;
}