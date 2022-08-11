# Phonebook
---
## Phonebook v1 (phonebook01.c)

### 기능

- **add {name} {phone number}**: 새로운 사람 추가
- **find {name}**: 이름으로 전화번호 검색
- **status**: 전화번호부에 저장된 모든 사람 출력
- **delete {name}**: 전화번호부에서 삭제
- **exit**: 프로그램 종료

### 실행 예

- 프로그램을 실행하면 화면에 프롬프트($)를 출력하고 사용자의 명령을 기다린다.

**$ add John 01011112222**

John was added successfully.

**$ add David 01033334444**

David was added successfully.

**$ fine Henry**

No person named ‘Henry’ exists.

**$ fine David**

01033334444

**$ status**

John 01011112222

David 01033334444

Total 2 persons.

**$ delete Jim**

No person named ‘Jim’ exists.

**$ delete John**

John was deleted successfully.

**$ status**

David 01033334444

Total 1 persons.

**$ exit**

---

## Phonebook v2

### v2 추가 기능

- **read {file name}**: 파일로부터 데이터를 읽어옴

- **save as {file name}**: 파일에 데이터를 저장

- **정렬**: 항상 알파벳 순으로 정렬