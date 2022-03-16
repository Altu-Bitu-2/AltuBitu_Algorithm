#include <iostream>
#include <deque>
#include <set>
#include<string.h>
using namespace std;

int main(){
    multiset<char> s;
    deque<char> d;
    string str;

    cin >> str;
    for(int i=0; i<str.length();i++){ //알파벡 사전순으로 정렬
        s.insert(str[i]);
    }

    for(auto iter=s.begin();iter !=s.end();iter++){

        if(d.empty()){ //덱이 비어있을 때 덱 앞부분에 삽입
            d.push_front(*iter);
            continue;

        }

        else if(strcmp(d.front() == iter)){ //set의 다음 문자가 덱의 front에 넣은 문자와 같다면 덱의 rear에 삽입, 문자 비교함수 쓰고 싶은데 에러남

            d.push_back(*iter);

        }
        else{ //앞서 넣은 front와 같지 않다면 front에 삽입
            d.push_front(*iter);
        }
    }

    if(s.size()==d.size()){ //팰린드롬이 만들어지면
        while(!d.empty()){
            cout <<d.front();
            d.pop_front();;
        }
    }
    else{
        cout <<"I'm Sorry Hansoo";
    }

    return 0;

}
