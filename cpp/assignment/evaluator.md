1. string read_protion( ) 함수는 표준 입력으로부터 식을 읽고 반환하는, 사용자가 제공한 식을 나타내는 문자열입니다.
- 사용자 입력이 올바른 형식의 infix 산술식이라고 가정할 수 있습니다(즉, 오류 검사 없음).
- 다음 조건을 만족하는 경우 infix:
(1) 모든 연산자 α,-,* 및 /)는 이진수이다.
(2) 피연산자는 숫자 또는 변수이며,
(3) 모든 연산을 괄호 안에 넣을 필요는 없다.
// 요구사항: infix 식 문자열이 반환되었습니다(예: "(1.03 * x + .4) / y")

1. convert_to_postfix(문자열 s)함수:  s(infix 산술식)를 postfix로 변환하는 함수
표기법과 결과 문자열을 반환합니다
- 전제 조건: s는 올바른 형식의 infix 산술식입니다(즉, 오류 확인이 필요 없음).
- 다음 조건이 충족되는 경우:
(1) 모든 연산자 α,-,* 및 /)는 이진수이다.
(2) 피연산자는 숫자 또는 변수이며,
(3) 모든 연산을 괄호 안에 넣을 필요는 없다.
- post condition: s에서 변환된 postfix 식의 문자열이 반환되고 postfix
문자열은 피연산자/연산자 사이에 공백이 하나 이상 있어야 합니다. (예: 10 2 * .4 + )

3. postfix 산술식인 문자열 s를 평가하는 이중 평가_postfix(string s) 함수와
결과를 반환합니다. 식에 있는 변수를 평가해야 하는데 아직 값이 알려져 있지 않은 경우,
평가 루틴은 사용자에게 표준 입력으로부터 값을 입력하도록 요청해야 한다.
- post condition: 문자열 s는 올바른 형식의 사후 픽스 산술식입니다(예: 오류 검사 필요 없음).