본격적으로 코드를 작성하기 전에 반드시 프로그램 디자인부터 해야 한다.
특히 팀 단위로 프로그램을 작성할 때는 사용할 데이터 구조나 클래스에 대한 분석 작업부터 먼저 해야 한다.
프로그램을 작성 함께 작성하는 다른 동료의 계획을 전혀 모른 채 무작정 코드부터 작성하는 것은 상당히 위험하다.

c++ 디자인에서 가장 핵심적인 원칙은 추상화(abstraction & capsulation) 과 재사용(reuse) 이다.
재사용에는 코드 재사용 뿐 아니라 디자인 재사용도 포함된다.

코드 재사용시 상기할 것

1. 재사용하면 개발 진행이 빠를 것 같으나, 처음 사용하는 라이브러리라면 학습 오버헤드로 인해 초반 진행이 더딜 수 있다.
   이건 감안해야 한다.

2. 성능/보안과 같은 비기능적인 요소도 리뷰해야 한다.
   성능은 빅오표기 을 참조하겠지만 빅오표기는 입력 크기가 무한히 커진다는 전제에 따라 시간 복잡도를 표현한다.
   그래서 입력 크기가 작을 때는 전혀 다른 성능 결과가 나올 수도 있으니, 입력 크기도 함께 고려해야 한다.

3. 라이센스와 유지보수 업데이트 현황이 어떤지 면밀히 검토해야 한다.
   GPL 라이센스의 경우 최종 결과물에 대한 소스 공개 의무를 지고 있으니, 사용자에게 제공되는 결과물에는 반영해선 안된다.

4. 멀티스레드 제약 사항도 확인해야 한다.

5. api 에서 리턴하는 모든 값이나 레퍼런스/익셉션을 모두 파악하고 처리해야 한다.
   나 자신도, 팀원들에게도 꼭 주지!


라이브러리는 직교성(orthogonality)를 지켜야 한다.

Orthogonality (직교성)
- 서로 다른 Component가 공존 가능하고, 문제를 일으키지 않아야 한다.
- 모든 데이터형을 일관성있게 대할 수 있어야 한다.
- 비일반성 : 문맥과 관계없는 제한
- 비직교성 : 문맥에 의존하는 제한
